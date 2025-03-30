//memoization
class Solution {
  public:
    int f(int i,int k,vector<int> price,vector<vector<int>>& dp){
        if(i==0){
            return k*price[0];
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int np=f(i-1,k,price,dp);
        int p=-1e9;
        if(i+1<=k){
            p=price[i]+f(i,k-(i+1),price,dp);
        }
        return dp[i][k]=max(p,np);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }
};

//tabulation
class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i]=price[0]*(i);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int np=dp[i-1][j];
                int p=-1e9;
                if(i+1<=j){
                    p=price[i]+dp[i][j-(i+1)];
                }
                dp[i][j]=max(p,np);
            }
        }
        return dp[n-1][n];
        
    }


};
