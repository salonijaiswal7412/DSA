class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int c=0;
        vector<int> idx;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                idx.push_back(i);
                c++;
            }
        }
        if(c!=0 && c!=2) return false;
        unordered_map<char,int> m1,m2;

        for(int i:idx){
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        for(auto [i,j]:m1){
            if(m1[i]!=m2[i]) return false;
        }
        return true;

        
    }
};
