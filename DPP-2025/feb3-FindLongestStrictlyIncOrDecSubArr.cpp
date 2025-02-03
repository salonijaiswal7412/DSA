class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int ans,inc=1,dec=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                dec++;
                inc=1;
            }
            else if(nums[i]<nums[i+1]){
                inc++;
                dec=1;
            }
            else {
                inc=1;dec=1;
            }
            
            ans=max(ans,max(inc,dec));
        }
        
        return ans;
        
    }
};
