#include<bits/stdc++.h>
using namespace std;
void dfs(int r,int c,int m,int n,vector<vector<int>>& vis,vector<vector<int>>& matrix){
    vis[r][c]=1;
    for(int i=0;i<m;i++){
        if(matrix[i][c] && !vis[i][c]){
            dfs(i,c,m,n,vis,matrix);
        }
    }
    for(int i=0;i<n;i++){
        if(matrix[r][i] && !vis[r][i]){
            dfs(r,i,m,n,vis,matrix);
        }
    }
}

int solve(vector<vector<int>> matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    vector<vector<int>>vis(m,vector<int>(n,0));
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && matrix[i][j]==1)
            {
                ans++;
            dfs(i,j,m,n,vis,matrix);
            }
            
        }
    }
    return ans;

}
