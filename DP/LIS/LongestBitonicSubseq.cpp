//strictly inc then dec
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> dp(n,1);
        vector<int> dp2(n,1);
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    dp[i]=max(dp[i],dp[prev]+1);
                }
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int prev=n-1;prev>i;prev--){
                if(nums[prev]<nums[i]){
                    dp2[i]=max(dp2[i],dp2[prev]+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]>1 && dp2[i]>1)//ensures strictly inc then dec
            ans=max(ans,dp[i]+dp2[i]-1);
        }
        return ans;
        
    }
};
