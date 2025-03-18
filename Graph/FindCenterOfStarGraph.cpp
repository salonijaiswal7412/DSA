class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> m;
        int v=0;
        for(auto i:edges){
            m[i[0]]++;
            m[i[1]]++;
            v++;
        }
        for(auto& i:m){
            if(i.second==v){
                return i.first;
            }
        }
        return -1;
        
    }
};
