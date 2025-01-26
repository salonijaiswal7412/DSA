//my approach as that used in surrounded regions
class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid){
        vis[i][j]=1;

        int m=grid.size();
        int n=grid[0].size();

        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        for(int x=0;x<4;x++){
            int r=i+dr[x];
            int c=j+dc[x];

            if(r>=0 && r< m && c>=0 && c<n && !vis[r][c] && grid[r][c]==1){
                dfs(r,c,vis,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,vis,grid);
            }
            if(!vis[i][n-1] && grid[i][n-1]==1){
                dfs(i,n-1,vis,grid);
            }
        }

        for(int j=0;j<n;j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,vis,grid);
            }
            if(!vis[m-1][j] && grid[m-1][j]==1){
                dfs(m-1,j,vis,grid);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
