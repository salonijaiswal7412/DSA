//memoization
class Solution {
public:
    int f(int i,int j,string s,string t,vector<vector<int>>& dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
        }
        return dp[i][j]=f(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int m=s.size(),n=t.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,s,t,dp);
        
    }
};
//tabulation
class Solution {
public:
    int mod=1e9+7;
    int numDistinct(string s, string t) {
        int m=s.size(),n=t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++) dp[i][0]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                }
                else{
                    dp[i][j]=dp[i-1][j]%mod;
                }
            }
        }
        return dp[m][n];
        
    }
};
