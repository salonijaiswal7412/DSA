//tabulation 
class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int m=s1.size(),n=s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=0;i<n;i++) dp[0][i]=0;
        for(int i=0;i<m;i++) dp[i][0]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else dp[i][j]=0;
            }
        }
        return ans;
    }
};

//memoization
class Solution {
  public:
    int f(int i,int j,string s1,string s2,vector<vector<int>>& dp,int& ans){
        if(i<0 ||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            dp[i][j]=1+f(i-1,j-1,s1,s2,dp,ans);
            ans=max(ans,dp[i][j]);
        }
        else dp[i][j]=0;
        return dp[i][j];
        
    }
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int m=s1.size(),n=s2.size();
        int ans=0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                f(i,j,s1,s2,dp,ans);
            }
        }
        return ans;
    }
};
