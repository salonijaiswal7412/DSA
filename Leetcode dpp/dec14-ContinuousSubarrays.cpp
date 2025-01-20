class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size(),l=0,r=0;
        long long ans=0;
        map<int,int> m;
        while(r<n){
            m[nums[r]]++;

            while(m.rbegin()->first-m.begin()->first>2){
                m[nums[l]]--;
                if(m[nums[l]]==0){
                    m.erase(nums[l]);
                }
                l++;
            }

            ans+=r-l+1;
            r++;
        }
        return ans;
        
    }
};
