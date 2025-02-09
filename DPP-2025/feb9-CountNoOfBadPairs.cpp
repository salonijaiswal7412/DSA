class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        long long good=0,n=nums.size();
        for(int i=0;i<n;i++){
            int temp=nums[i]-i;
            good+=m[temp];
            m[temp]++;
        }
        return (n*(n-1))/2-good;
        
    }
};
