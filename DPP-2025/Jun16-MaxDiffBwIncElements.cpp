class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=INT_MIN;
        int mini=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            ans=max(ans,nums[i]-mini);
        }
        return ans<=0?-1:ans;
        
        
    }
};
