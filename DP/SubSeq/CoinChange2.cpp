//memoization
class Solution {
public:
    int f(int i,int t,vector<int>& arr,vector<vector<int>>& dp){
        if(i==0){
            return (t%arr[i]==0);
        }
        if(dp[i][t]!=-1) return dp[i][t];

        int np=f(i-1,t,arr,dp);
        int p=0;
        if(arr[i]<=t) p=f(i,t-arr[i],arr,dp);

        return dp[i][t]=p+np;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return f(n-1,amount,coins,dp);
        
    }
};

//tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                long long int np=dp[i-1][j];
                long long int p=0;
                if(coins[i]<=j) p=dp[i][j-coins[i]];
                dp[i][j]=p+np;
            }
        }
        return dp[n-1][amount];
        
    }
};
