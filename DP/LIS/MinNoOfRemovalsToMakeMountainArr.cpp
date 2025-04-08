//just like bitonic only return n-ans
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> lis(n,1);
        vector<int> lds(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev]){
                    lis[i]=max(lis[i],lis[prev]+1);
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int prev=n-1;prev>i;prev--){
                if(nums[i]>nums[prev]){
                    lds[i]=max(lds[i],lds[prev]+1);
                }
            }
        }
        int temp=0;
        for(int i=0;i<n;i++){
            if(lis[i]>1  && lds[i]>1)
            temp=max(temp,lis[i]+lds[i]-1);
        }
        return n-temp;

    }
};
