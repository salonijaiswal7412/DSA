class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int> m;
        for(auto& i:nums1){
            m[i[0]]+=i[1];
        }
        for(auto& i:nums2){
            m[i[0]]+=i[1];
        }
        vector<vector<int>> ans;
        for(auto& i:m){
            ans.push_back({i.first,i.second});
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
