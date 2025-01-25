//bfs
class Solution {
public:
    void bfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[r][c]=1;
        queue<pair<int,int>> q;
        q.push({r,c});
        int m=grid.size();
        int n=grid[0].size();

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    bfs(i,j,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
//dfs
class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[r][c]=1;
        
        int m=grid.size();
        int n=grid[0].size();

        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        for(int i=0;i<4;i++){
            int nrow=r+dr[i];
            int ncol=c+dc[i];
            
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]=='1')
              dfs(nrow,ncol,vis,grid);
        }

        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    dfs(i,j,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
