class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int l=0,c=1;
        for(int r=0;r<nums.size();r++){
            if(r>0 && nums[r-1]+1==nums[r]){
                c++;
            }
            if(r-l+1>k){
                if(nums[l]+1==nums[l+1]){
                    c--;
                }
                l++;
            }
            if(r-l+1==k){
                ans.push_back(c==k?nums[r]:-1);
            }
        }
        return ans;
        
    }
};
