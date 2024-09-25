class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, maxl = 0;
        while (r < nums.size()) {
            if (nums[r] == 0)
                k--;
            if (k < 0) {
                if (nums[l] == 0) {
                    k++;
                    
                }
                l++;
            }
            maxl = max(maxl, r - l + 1);
            r++;
        }
        return maxl;
    }
};