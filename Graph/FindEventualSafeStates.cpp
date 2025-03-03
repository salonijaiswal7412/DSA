class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> v(n);
        vector<int> ind(n,0);
        vector<bool> safe(n,false);
        queue<int>q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(auto j:graph[i]){
                v[j].push_back(i);
                ind[i]++;
            }
        }
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int f=q.front();
            q.pop();
            safe[f]=true;
            for(auto i:v[f]){
                if(--ind[i]==0){
                    q.push(i);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(safe[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
