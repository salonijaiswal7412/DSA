class Solution {
public:
    void backtrack(vector<int>& nums,int idx,int currOr,int maxOr,int& ans){
        if(currOr==maxOr)ans++;
        for(int i=idx;i<nums.size();++i){
            backtrack(nums,i+1,currOr|nums[i],maxOr,ans);
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
        for(int i:nums){
            maxOr|=i;
        }
        int ans=0;
        backtrack(nums,0,0,maxOr,ans);
        return ans;
        
    }
};