class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,h=0;
        int s=0,ans=INT_MAX;
        int n=nums.size();
        while(h<n){
            s+=nums[h];
            while(s>=target){
                ans=min(ans,h-l+1);
                s-=nums[l++];
            }
            h++;
        }
        if(ans==INT_MAX) return 0;
        return ans;
        
    }
};