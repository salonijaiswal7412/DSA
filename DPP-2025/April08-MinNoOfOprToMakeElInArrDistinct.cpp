class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int x=-1;
        unordered_map<int,int> m;
        for(int i=n-1;i>=0;i--){
            if(m.find(nums[i])!=m.end()){
                x=i;
                break;
            }
            m[nums[i]]++;
        }
        return x==-1?0:x/3+1;
        
        
    }
};
