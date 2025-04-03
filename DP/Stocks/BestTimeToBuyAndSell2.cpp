//memoization
class Solution {
public:
    int f(int i,int buy,vector<int>&prices,vector<vector<int>>& dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-prices[i]+f(i+1,0,prices,dp),f(i+1,1,prices,dp));
        }
        else return dp[i][buy]=max(prices[i]+f(i+1,1,prices,dp),f(i+1,0,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
        
    }
};
//tabulation
class Solution {
public:
    int f(int i,int buy,vector<int>&prices,vector<vector<int>>& dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-prices[i]+f(i+1,0,prices,dp),f(i+1,1,prices,dp));
        }
        else return dp[i][buy]=max(prices[i]+f(i+1,1,prices,dp),f(i+1,0,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    dp[i][j]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
        
    }
};
//space optimized
class Solution {
public:
    int f(int i,int buy,vector<int>&prices,vector<vector<int>>& dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-prices[i]+f(i+1,0,prices,dp),f(i+1,1,prices,dp));
        }
        else return dp[i][buy]=max(prices[i]+f(i+1,1,prices,dp),f(i+1,0,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> ahead(2,0),curr(2,0);
        ahead[0]=ahead[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    curr[j]=max(-prices[i]+ahead[0],ahead[1]);
                }
                else{
                    curr[j]=max(prices[i]+ahead[1],ahead[0]);
                }
            }
            ahead=curr;
        }
        return ahead[1];
        
    }
};
