//memoization
class Solution {
public:
    int f(int i,int t,vector<int>& a,vector<vector<int>>& dp){
        if(i==0){
            if(t%a[i]==0) return t/a[i];
            return 1e9;
        }
        if(dp[i][t]!=-1) return dp[i][t];
        int nottake=0+f(i-1,t,a,dp);
        int take=1e9;
        if(a[i]<=t){
            take=1+f(i,t-a[i],a,dp);
        }
        return dp[i][t]=min(take,nottake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=f(n-1,amount,coins,dp);
        if(ans>=1e9) return -1;
        return ans; 

        
    }
};

//tabulation
class Solution {
public:
    int coinChange(vector<int>& a, int t) {
        int n=a.size();
        vector<vector<int>> dp(n,vector<int>(t+1,0));
        for(int i=0;i<=t;i++){
            if(i%a[0]==0){
                dp[0][i]=i/a[0];
            }
            else dp[0][i]=1e9;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=t;j++){
                int NT=0+dp[i-1][j];
                int T=1e9;
                if(a[i]<=j){
                    T=1+dp[i][j-a[i]];
                }
                dp[i][j]=min(T,NT);
            }
        }
        return dp[n-1][t]==1e9?-1:dp[n-1][t];
        
    }
};
