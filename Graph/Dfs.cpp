public:
    void dfs(int node,vector<int> adj[],int vis[],vector<int>& ans){
        vis[node]=1;
        ans.push_back(node);
        for(auto i: adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis,ans);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        int vis[V]={0};
        dfs(0,adj,vis,ans);
        return ans;
    }