class Solution {
public:
    void backtrack(vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp,vector<int>& freq){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i]=1;
                temp.push_back(nums[i]);
                backtrack(nums,ans,temp,freq);
                freq[i]=0;
                temp.pop_back();
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> freq(n,0);
        backtrack(nums,ans,temp,freq);
        return ans;
        
    }
};