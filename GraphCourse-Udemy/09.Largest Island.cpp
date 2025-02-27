#include<bits/stdc++.h>
using namespace std;
void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>& grid,int& size){
    vis[r][c]=1;
    size++;
    int m=grid.size();
    int n=grid[0].size();
    int dr[]={-1,0,1,0};
    int dc[]={0,-1,0,1};
    
    for(int i=0;i<4;i++){
        int nrow=r+dr[i];
        int ncol=c+dc[i];
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
            
            dfs(nrow,ncol,vis,grid,size);
        }
    }
    
}
int maxAreaOfIsland(vector<vector<int>> grid)
{
    int ans=0;
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> vis(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && grid[i][j]){
                int size=0;
                dfs(i,j,vis,grid,size);
                ans=max(ans,size);
            }
        }
        
    }
    return ans;
    
}
