class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(auto i:grid){
            for(int j: i){
                nums.push_back(j);
            }
        }
        int ans=0;
        int n=nums.size();
        nth_element(nums.begin(),nums.begin()+n/2,nums.end());
        int y=nums[n/2];
        for(int i:nums){
            if(i%x!=y%x) return -1;
            ans+=(abs(y-i)/x);
        }
        return ans;
        
    }
};
