class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int p=nums[i]*nums[j];
                ans+=8*m[p];
                m[p]++;
            }
        }
        return ans;
        
    }
};
