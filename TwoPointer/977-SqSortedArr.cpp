class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*nums[i];
        }
        int l=0,r=nums.size()-1,i=nums.size()-1;
        while(l<=r){
            if(nums[l]>nums[r]){
                ans[i]=nums[l];
                l++;
                i--;
            }
            else{
                ans[i]=nums[r];
                r--;
                i--;
            }
        }
        return ans;
        
    }
};
