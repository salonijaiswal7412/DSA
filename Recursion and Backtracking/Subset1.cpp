class Solution {
public:
    void calculate(int i, vector<int>& nums, vector<int>& subset,vector<vector<int>>& ans) {
        if(i==nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        calculate(i+1,nums,subset,ans);
        subset.pop_back();
        calculate(i+1,nums,subset,ans);        

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        calculate(0, nums, subset, ans);
        return ans;
    }
};