class Solution {
public:
    int solve(vector<int>& nums,int div){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%div)
            ans+=nums[i]/div+1;
            else ans+=nums[i]/div;
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n=nums.size();
        int h=*max_element(nums.begin(),nums.end());
        int l=1;
        int ans=h;
        while(l<=h){
            int m=l+(h-l)/2;
            if(solve(nums,m)<=threshold){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;

    }
};
