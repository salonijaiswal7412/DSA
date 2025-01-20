class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long int> pre(nums.size());
        long long int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            pre[i]=s;
        }
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            if((pre[i])>=(pre[nums.size()-1]-pre[i]))
            ans++;
            
        }
        return ans;
        
    }
};
