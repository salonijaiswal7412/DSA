class Solution {
    public:
        bool dfs(int r,int c,int pr,int pc,vector<vector<int>>& vis,vector<vector<char>>& grid,int d){
            int m=grid.size(),n=grid[0].size();
            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            vis[r][c]=1;
            for(int i=0;i<4;i++){
                int nrow=r+dr[i];
                int ncol=c+dc[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==grid[r][c]){
                    if(!vis[nrow][ncol]){
                        if(dfs(nrow,ncol,r,c,vis,grid,d+1)) return true;
                    }
                    else if(nrow!=pr || ncol!=pc){
                        if(d>=4) return true;
                    }
                }
            }
            return false;
        }
        bool containsCycle(vector<vector<char>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
            vector<vector<int>> vis(m,vector<int>(n,0));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(!vis[i][j]){
                        if(dfs(i,j,-1,-1,vis,grid,1))return true;
                    }
                }
            }
            return false;
            
        }
    };