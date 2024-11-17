class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long> pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
        }

        deque<int> d;
        int ans=INT_MAX;
        for(int i=0;i<=n;i++){
            while(!d.empty() && pre[i]-pre[d.front()]>=k){
                ans=min(ans,i-d.front());
                d.pop_front();
            }

            while(!d.empty() && pre[i]<=pre[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
        }
        return ans==INT_MAX?-1:ans;
        
    }
};
