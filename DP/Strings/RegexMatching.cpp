//memoization
class Solution {
public:
    bool f(int i,int j,string& s,string&p,vector<vector<int>>&dp){
        if(i==s.size() && j==p.size()) return true;
        if(j==p.size()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(j+1<p.size() && p[j+1]=='*'){
            if(f(i,j+2,s,p,dp))
            return dp[i][j]= true;

            if(i<s.size() && (s[i]==p[j]||p[j]=='.')){
                if(f(i+1,j,s,p,dp))return dp[i][j]= true;
            }
        }
        if (i < s.length() && (s[i] == p[j] || p[j] == '.')) {
            return dp[i][j]=f(i + 1, j + 1, s, p,dp);
        }
        return dp[i][j]=false;


    }
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(0,0,s,p,dp);
        
    }
};
//tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
    int m=s.size(),n=p.size();
    vector<vector<bool>> dp(m+1,vector<bool>(n+1,0));
    dp[0][0]=1;

    for(int j=2;j<=n;j++){
        if(p[j-1]=='*'){
            dp[0][j]=dp[0][j-2];
        }
    }        

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==p[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else if(p[j-1]=='*'){
                dp[i][j]=dp[i][j-2];
                if(p[j-2]=='.' ||s[i-1]==p[j-2]){
                    dp[i][j]=dp[i][j]||dp[i-1][j];
                }
            }
            else{
                dp[i][j]=false;
            }
        }
        
    }
    return dp[m][n];
    }
};
