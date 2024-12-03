//memoization
class Solution {
public:
    int f(int i,int j,vector<vector<int>>& obs,vector<vector<int>>& dp){
        if(i<0 || j<0 || obs[i][j]==1) return 0;
        if(i==0 && j==0 ) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int u=f(i-1,j,obs,dp);
        int l=f(i,j-1,obs,dp);
        return dp[i][j]=u+l;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m=obs.size();
        int n=obs[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return f(m-1,n-1,obs,dp);
        
    }
};

//tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m=obs.size();
        int n=obs[0].size();
        if(obs[0][0]==1 ) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;continue;
                }
                if(obs[i][j]==1){
                    dp[i][j]=0 ;
                    continue;
                }
                int u=0,l=0;
                if(i>0) u=dp[i-1][j];
                if(j>0) l=dp[i][j-1];

                dp[i][j]=u+l;
            }
        }
        return dp[m-1][n-1];
    }
};
