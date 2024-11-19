
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int l=0,r;
        long long last=0;
        for(r=0;r<k;r++){
            m[nums[r]]++;
            last+=nums[r];
        }
        long long ans=0;
        while(r<=nums.size()){
            if(m.size()==k){
                ans=max(ans,last);
            }
            if(l<nums.size()){
                m[nums[l]]--;
                if(m[nums[l]]==0){m.erase(nums[l]);}
                last-=nums[l];
                l++;
            }
            if(r<nums.size()){
                m[nums[r]]++;
                last+=nums[r];
            }
            r++;
        }
        return ans;
    }
};
