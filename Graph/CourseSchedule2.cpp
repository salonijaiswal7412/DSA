//bfs topological sort-better option

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {

        vector<vector<int>> v(n);
        for(auto& i:pre){
            v[i[1]].push_back(i[0]);
        }
        vector<int> ind(n,0);
        for(int i=0;i<n;i++){
            for(auto j: v[i]){
                ind[j]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
                
            }
        }
        while(!q.empty()){
            int f=q.front();
            ans.push_back(f);
            q.pop();
            for(auto i:v[f]){
                ind[i]--;
                if(ind[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size()==n)return ans;
        return {};
        
    }
};

//dfs topological sort
class Solution {
public:
    bool dfs(int n,vector<bool>& vis,vector<int>& ans,vector<vector<int>>&v,vector<bool>& path){
        vis[n]=true;
        path[n]=true;
        for(auto i:v[n]){
            if(!vis[i]){
                if(dfs(i,vis,ans,v,path))return true;
            }
            else if(path[i])return true;
        }
        path[n]=false;
        ans.push_back(n);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> v(n);
        for(auto i:pre){
            v[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n,0);
        vector<int> ans;
        vector<bool>path(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,ans,v,path))return {};
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};
