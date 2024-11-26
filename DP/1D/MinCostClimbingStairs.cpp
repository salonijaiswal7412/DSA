//memoization
class Solution {
public:
    int f(vector<int>& cost,int n,vector<int>& dp){
        if(n<0) return 0;
        if(n==0 || n==1) return cost[n];
        if(dp[n]!=-1) return dp[n];
        return dp[n]=cost[n]+min(f(cost,n-1,dp),f(cost,n-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(f(cost,n-1,dp),f(cost,n-2,dp));

        
    }
};
//tabulation
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
        
    }
};
//space optimization
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        
        int a=cost[0];
        int b=cost[1];
        for(int i=2;i<n;i++){
            int curr=cost[i]+min(a,b);
            a=b;
            b=curr;

        }
        return min(a,b);
        
    }
};
