class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int ,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        unordered_set<int> s;
        for(auto [key,val]:m){
            if(s.count(val)!=0) return false;
            s.insert(val);
        }
        return true;
        
    }
};
