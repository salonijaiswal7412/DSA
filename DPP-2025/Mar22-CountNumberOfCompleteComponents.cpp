//using dfs
class Solution {
public:
    void dfs(int node,int n,vector<vector<int>>& v,vector<int>& component,vector<bool>& vis){
        vis[node]=true;
        component.push_back(node);
        for(auto& i: v[node]){
            if(!vis[i]){
                dfs(i,n,v,component,vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
        for(auto& i:edges){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        int ans=0;
        vector<bool> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> component;
                dfs(i,n,v,component,vis);
                bool isComplete=true;
                int size=component.size();
                for(auto j:component){
                    if(v[j].size()!=size-1){
                        isComplete=false;
                        break;
                    }
                }
                if(isComplete) ans++;
            }
        }
        return ans;
        
    }
};
