class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> deg(n+1,0);
        vector<vector<int>> edges(n,vector<int>(n,0));
        for(auto& i:roads){
            int a=i[0],b=i[1];
            deg[a]++;
            deg[b]++;
            edges[a][b]++;
            edges[b][a]++;
        }
        int ans=-1e9;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,deg[i]+deg[j]-edges[i][j]);
            }
        }
        return ans;
        
    }
};
