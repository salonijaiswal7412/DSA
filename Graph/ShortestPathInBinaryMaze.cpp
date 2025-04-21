class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0) return -1;
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        vector<vector<int>> dis(n,vector<int>(n,0));
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        dis[0][0]=1;
        vis[0][0]=1;
        int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        while(!q.empty()){
            int m=q.size();
            for(int i=0;i<m;i++){
                auto f=q.front();
                q.pop();
                int r=f.first;
                int c=f.second;
                for(int it=0;it<8;it++){
                    int nr=r+dir[it][0];
                    int nc=c+dir[it][1];
                    if(nr>=0 && nr<n && nc>=0 && nc<n){
                        if(!vis[nr][nc]&& grid[nr][nc]==0){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                        dis[nr][nc]=dis[r][c]+1;
                        }
                    }
                }
            }
        }
        return dis[n-1][n-1]==0?-1:dis[n-1][n-1];

        
    }
};
