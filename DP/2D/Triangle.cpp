//memoization
class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& t,vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==t.size()-1) return t[i][j];
        int d=t[i][j]+helper(i+1,j,t,dp);
        int dg=t[i][j]+helper(i+1,j+1,t,dp);

        return dp[i][j]=min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(0,0,triangle,dp);
        
    }
};

//tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int j=0;j<n;j++){
            dp[n-1][j]=t[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d=t[i][j]+dp[i+1][j];
                int dg=t[i][j]+dp[i+1][j+1];

                dp[i][j]=min(d,dg);
            }
        }
        return dp[0][0];

        
    }
};

//space optimized code 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<int> front(n);
        vector<int> curr(n);

        for (int j = 0; j < n; j++) {
            front[j] = t[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--) {

            for (int j = i; j >= 0; j--) {
                int d = t[i][j] + front[j];
                int dg = t[i][j] + front[j + 1];

                curr[j] = min(d, dg);
            }
            front = curr;
        }
        return front[0];
    }
};
