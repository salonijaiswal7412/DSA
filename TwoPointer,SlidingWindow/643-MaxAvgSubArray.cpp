class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0,r=k;
        double ans=INT_MIN;
        double s=0;
        for(int i=0;i<k;i++){
            s+=nums[i];

        }
        ans=max(ans,s/k);
        while(r<nums.size()){
             s-=nums[l++];
            s+=nums[r++];
           
            ans=max(ans,s/k);

        }
        return ans;
        
    }
};