//dumb ques
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]++;
            if(i<k) return -1;
        }
        int ans=0;
        for(auto& i:m){
            if(i.first>k){
                ans++;
            }
        }
        return ans;
        
        
    }
};
