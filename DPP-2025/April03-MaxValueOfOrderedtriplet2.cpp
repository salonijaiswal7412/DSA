class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n,0);
        vector<int> suff(n,0);
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=max(nums[i],pre[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=max(nums[i],suff[i+1]);
        }
        long long ans=0;
        for(int j=1;j<n-1;j++){
            long long temp=((long long)(pre[j-1]-nums[j])*suff[j+1]);
            ans=max(temp,ans);
        }
        return ans;
        
    }
};
