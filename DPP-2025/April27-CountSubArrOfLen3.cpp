class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-2;i++){
            int j=i+1,k=j+1;
            if(j<n-1 && k<n && (nums[i]+nums[k])*2==nums[j]){
                ans++;
            }
        }
        return ans;
    }
};
