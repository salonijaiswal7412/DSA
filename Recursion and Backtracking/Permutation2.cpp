class Solution {
public:
    void f(vector<int>& nums,vector<int>& freq,vector<int>& temp,vector<vector<int>>& ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
        }
        for(int i=0;i<nums.size();i++){  
            if(freq[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !freq[i-1]) continue;
            freq[i]=1;
            temp.push_back(nums[i]);
            f(nums,freq,temp,ans);
            temp.pop_back();
            freq[i]=0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> freq(n,0);
        vector<int> temp;
        vector<vector<int>> ans;
        f(nums,freq,temp,ans);
        return ans;
    }
};
