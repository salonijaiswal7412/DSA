//using dfs
class Solution {
public:
    void dfs(int n,vector<int> adj[],vector<int>& vis){
        vis[n]=1;
        for(auto i:adj[n]){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int> vis(v,0);
        vector<int> adj[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int c=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                c++;
            }
        }
        return c;
    }
};

//using bfs
class Solution {
public:
    void bfs(int n,vector<int> adj[],vector<int>& vis){
        queue<int> q;
        q.push(n);
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto i:adj[node]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push(i);
                    
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int> vis(v,0);
        vector<int> adj[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int c=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                bfs(i,adj,vis);
                c++;
            }
        }
        return c;
    }
};