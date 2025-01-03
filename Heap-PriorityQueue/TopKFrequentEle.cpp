class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i:nums){
            m[i]++;
        }
        priority_queue<pair<int,int>> p;
        for(auto i:m){
            p.push({i.second,i.first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(p.top().second);
            p.pop();

        }
        return ans;
        
    }
};