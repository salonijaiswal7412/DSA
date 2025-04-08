//uses 1d dp 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
        
    }
};
