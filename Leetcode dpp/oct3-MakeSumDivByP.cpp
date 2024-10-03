class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long s=0;
        for(auto i:nums)s+=i;
        int rem=s%p;
        if(rem==0) return 0;

        int n=nums.size();
        int minl=n;
        s=0;
        unordered_map<int,int> m;
        m[0]=-1;
        for(int i=0;i<n;i++){
            s=(s+nums[i])%p;
            int target=(s-rem+p)%p;
            if(m.find(target)!=m.end()){
                minl=min(minl,i-m[target]);
            }
            m[s]=i;
        }
        return (minl==n)?-1:minl;
        
    }
};