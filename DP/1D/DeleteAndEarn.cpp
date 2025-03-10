class Solution {
public:
    int solve(int i,int n,vector<int>& nums,vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int next=i;
        int curr=nums[i];
        int s=0;
        while(next<n && nums[next]==curr){
            s+=curr;
            next++;
        }
        while(next<n && nums[next]==curr+1){
            next++;
        }
        int ans=max(s+solve(next,n,nums,dp),solve(i+1,n,nums,dp));
        return dp[i]=ans;
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,-1);
        return solve(0,n,nums,dp);
        
    }
};
