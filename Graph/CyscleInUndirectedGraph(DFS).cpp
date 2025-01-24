class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node,int parent,vector<bool>& vis,vector<vector<int>>& adj){
        vis[node]=true;
        for(auto i: adj[node]){
            if(!vis[i]){
                if(dfs(i,node,vis,adj)) return true;
            }
            else if(vis[i] && i!=parent) return true;
        }
      return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int v=adj.size();
        vector<bool> vis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj)) return true;
            }
        }
        return false;
        
    }
};
