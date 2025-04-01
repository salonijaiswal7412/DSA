//memoization
class Solution {
public:
    bool f(int i,int j,string& p,string& s,vector<vector<int>>& dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0){
            for(int idx=0;idx<=i;idx++){
                if(p[idx]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[j]==p[i] ||p[i]=='?'){
            return dp[i][j]= f(i-1,j-1,p,s,dp);
        }
        if(p[i]=='*'){
            return dp[i][j]=f(i-1,j,p,s,dp)|| f(i,j-1,p,s,dp);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int m=p.size(),n=s.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,p,s,dp);
        
    }
};
//tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=p.size(),n=s.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=1;
        for(int i=1;i<=n;i++) dp[0][i]=false;
        for(int i=1;i<=m;i++){
            bool flag=true;
            for(int j=0;j<i;j++){
                if(p[j]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[i][0]=flag;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[i-1]==s[j-1] || p[i-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i-1]=='*'){
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                }
                else
                dp[i][j]=false;
            }
        }
        return dp[m][n];
        
    }
};
