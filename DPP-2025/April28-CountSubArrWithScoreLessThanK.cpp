class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        int n=nums.size(),l=0;
        long long s=0;
        for(int r=0;r<n;r++){
            s+=nums[r];
            while(s*(r-l+1)>=k){
                s-=nums[l++];
            }
            ans+=(r-l+1);
        }
        return ans;
        
    }
};
