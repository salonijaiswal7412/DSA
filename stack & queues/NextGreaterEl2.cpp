class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> s;
        for(int i=2*n-1;i>=0;i--){
            while(!s.empty() && nums[i%n]>=s.top()){
                s.pop();
            }
            if(!s.empty() && i<n){
                ans[i]=s.top();
            }
            s.push(nums[i%n]);
        }
        return ans;

        
    }
};