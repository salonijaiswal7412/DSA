class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s=0,maxi=INT_MIN;
        for(auto i:nums){
            s=max(i,s+i);
            maxi=max(s,maxi);
        }
        return maxi;
        
    }
};
