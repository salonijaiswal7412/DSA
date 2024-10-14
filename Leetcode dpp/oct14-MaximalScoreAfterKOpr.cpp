class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto i:nums){
            pq.push(i);
        }
        long long ans=0;
        while(k!=0){
            ans+=pq.top();
            auto x=pq.top();
            pq.pop();
            pq.emplace((x+2)/3);
            k--;
        }
        return ans;
        
    }
};