class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.length() < 10)
            return ans;
        unordered_map<string, int> m;
        for(int i=0;i<=s.length()-10;i++){
            string substring=s.substr(i,10);
            if(m.count(substring)){
                if(m[substring]==1){
                    ans.push_back(substring);
                }
                m[substring]++;
            }
            else{
                m[substring]=1;
            }
        }
        return ans;
    }
};