class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        unordered_set<int>st;
        for(auto [val,occ]:mp){
            if(st.count(occ)!=0){
                return false;
            }
            st.insert(occ);
        }
        return true;
    }
};