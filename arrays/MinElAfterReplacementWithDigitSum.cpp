class Solution {
public:
    int sum(int n){
        int s=0;
        while(n!=0){
            s+=n%10;
            n/=10;
        }
        return s;
    }
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            nums[i]=sum(nums[i]);
            ans=min(ans,nums[i]);
        }
        return ans;
    }
    
};