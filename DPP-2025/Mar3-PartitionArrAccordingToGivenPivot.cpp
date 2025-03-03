class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> ans(n,0);
        int l=0,r=n-1;
        for(int i=0,j=n-1;i<n;i++,j--){
            if(nums[i]<pivot){
                ans[l++]=nums[i];
            }
            if(nums[j]>pivot){
                ans[r--]=nums[j];
            }
        }        
        for(int i=l;i<=r;i++){
            ans[i]=pivot;
        }
        return ans;
    }
};
