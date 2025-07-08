class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x=0;
        for(int i:nums){
            x^=i;
        }
        int y=x^k;
        return __builtin_popcount(y);
        
    }
};
