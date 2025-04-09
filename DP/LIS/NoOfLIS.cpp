class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxl=1;
        vector<int> dp(n,1),cnt(n,1);
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev] && dp[i]<dp[prev]+1){
                    dp[i]=dp[prev]+1;
                    cnt[i]=cnt[prev];
                }
                else if(nums[i]>nums[prev] && dp[i]==dp[prev]+1){
                    cnt[i]+=cnt[prev];
                }
            }
            maxl=max(maxl,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxl){
                ans+=cnt[i];
            }
        }
        return ans;
    }
};
