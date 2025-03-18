class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> deg(n+1,0);
        vector<vector<int>> v(n+1,vector<int>(n+1,0));
        for(auto& i:edges){
            int a=i[0],b=i[1];
            deg[a]++;
            deg[b]++;
            v[a][b]++;
            v[b][a]++;
        }
        int ans=1e9;
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int k=j+1;k<=n;k++){
                    if(v[i][j] && v[j][k] && v[k][i]){
                        ans=min(ans,deg[i]+deg[j]+deg[k]-6);
                    }
                }
            }
        }
        return ans==1e9?-1:ans;
        
    }
};
