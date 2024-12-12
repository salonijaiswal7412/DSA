//memoization
class Solution {
public:
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];

        int u=grid[i][j]+f(i-1,j,grid,dp);
        int l=grid[i][j]+f(i,j-1,grid,dp);

        return dp[i][j]=min(u,l);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,grid,dp); 
        
    }
};

//tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                    continue;

                }
                int u=grid[i][j],l=grid[i][j];
                u+=(i>0)?dp[i-1][j]:1e9;
                l+=(j>0)?dp[i][j-1]:1e9;

                dp[i][j]=min(u,l);
            }

        }
        return dp[m-1][n-1];

        
    }
};
