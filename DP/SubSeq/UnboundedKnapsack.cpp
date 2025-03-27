//memoization

class Solution {
  public:
    int f(int i,int t,vector<int> w,vector<int> v,vector<vector<int>>& dp){
        if(i==0){
            return (t/w[0])*v[0];
        }
        if(dp[i][t]!=-1) return dp[i][t];
        int np=f(i-1,t,w,v,dp);
        int p=-1e9;
        if(w[i]<=t){
            p=v[i]+f(i,t-w[i],w,v,dp);
        }
        return dp[i][t]=max(p,np);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        return  f(n-1,capacity,wt,val,dp);
    }
};

//tabulation

class Solution {
  public:
    int knapSack(vector<int>& v, vector<int>& w, int k) {
        // code here
        int n=w.size();
        vector<vector<int>> dp(n,vector<int>(k+1,0));
        for(int i=0;i<=k;i++){
            dp[0][i]=(i/w[0])*v[0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                int np=dp[i-1][j];
                int p=-1e9;
                if(w[i]<=j){
                    p=v[i]+dp[i][j-w[i]];
                    
                }
                dp[i][j]=max(p,np);
            }
        }
        return dp[n-1][k];
    }
};
