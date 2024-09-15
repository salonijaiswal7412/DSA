class Solution {
public:
    void findsub(int idx,vector<int> & nums,vector<int>& sub,vector<vector<int>>& ans){
        ans.push_back(sub);
        for(int i=idx;i<nums.size();i++){
            if(i!=idx && nums[i]==nums[i-1])continue;
            sub.push_back(nums[i]);
            findsub(i+1,nums,sub,ans);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        findsub(0, nums, sub, ans);
        return ans;
    }
};