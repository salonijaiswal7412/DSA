class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dis(V,1e8);
        dis[src]=0;
        for(int i=0;i<V-1;i++){
            for(auto j:edges){
                int u=j[0],v=j[1],w=j[2];
                if(dis[u]!=1e8 && dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                }
            }
        }
        for(auto i:edges){
            int u=i[0],v=i[1],w=i[2];
            if(dis[u]!=1e8 && dis[u]+w<dis[v]){
                return {-1};
            }
        }
        return dis;
    }
};
