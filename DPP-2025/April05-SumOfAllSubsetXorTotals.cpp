class Solution {
public:
    void generate(int i,vector<int>&temp,vector<int>&nums,vector<vector<int>>& subs){
        if(i==nums.size()){
            subs.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        generate(i+1,temp,nums,subs);
        temp.pop_back();
        generate(i+1,temp,nums,subs);
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<vector<int>> subs;
        vector<int> temp;
        int ans=0;
        generate(0,temp,nums,subs);
        for(auto i:subs){
            int xor_val=0;
            for(auto j: i){
                xor_val^=j;
            }
            ans+=xor_val;
        }
        return ans;
        
    }
};
