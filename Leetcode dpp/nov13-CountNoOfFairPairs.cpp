class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int l=i+1,h=n-1;
            int last=-1,first=-1;
            while(l<=h){
                int m=l+h;
                m>>=1;
                if(lower<=nums[i]+nums[m] && nums[i]+nums[m]<=upper){
                    last=m;
                    l=m+1;
                }
                else if(lower>nums[i]+nums[m]){
                    l=m+1;
                }
                else h=m-1;
            }
            l=i+1,h=n-1;
            while(l<=h){
                int m=l+h;
                m>>=1;
                if(lower<=nums[i]+nums[m] && nums[i]+nums[m]<=upper){
                    first=m;
                    h=m-1;
                }
                else if(lower>nums[i]+nums[m]){
                    l=m+1;
                }
                else h=m-1;
                
            }
            if(last!=-1){
                ans+=(last-first+1);
            }
        }
        return ans;
        
    }
};
