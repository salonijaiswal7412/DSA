class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxl=0;
        int m=max_element(nums.begin(),nums.end())-nums.begin();
        int x=nums[m];
        for(int i=m;i<n;i++){
            int l=0;
            while(i<n && nums[i]==x){
                i++;
                l++;
            }
            maxl=max(maxl,l);
        }
        return maxl;
        
    }
};