//memoization
class Solution {
public:
    int mod=1e9+7;
    int f(int i,int k,vector<int>& nums,vector<vector<int>>& dp){
        if(i==0){
            if(nums[0]==0 && k==0) return 2;
            if(nums[0]==k || k==0) return 1;
            return 0;
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int notpick=f(i-1,k,nums,dp);
        int pick=0;
        if(nums[i]<=k) pick=f(i-1,k-nums[i],nums,dp);

        return dp[i][k]=(pick+notpick)%mod;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        for(int i: nums)s+=i;
        if(s-target<0 ||(s-target)%2) return 0;
        int k=(s-target)/2;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return f(n-1,k,nums,dp);
        
    }
};
//tabulation
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        int n = nums.size();
        int s = 0;
        for (int i : nums)
            s += i;
        if ((s - target) < 0 || (s - target) % 2)
            return 0;
        int k = (s - target) / 2;
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        if (nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;
        if (nums[0] != 0 && nums[0] <= k)
            dp[0][nums[0]] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                int np = dp[i - 1][j];
                int p = 0;
                if (nums[i] <= j)
                    p = dp[i - 1][j - nums[i]];
                dp[i][j] = (p + np) % mod;
            }
        }
        return dp[n-1][k];
    }
};
