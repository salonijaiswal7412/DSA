class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string word=s1+" "+s2;
        unordered_map<string,int> m;
        string t="";
        for(auto ch:word){
            if(ch==' '){
                if(!t.empty()){
                    m[t]++;
                    t="";
                }
            }
            else{
                t+=ch;
            }
        }
        if(!t.empty()){
            m[t]++;
        }
        vector<string> ans;
        for(auto i:m){
            if(i.second==1){
                ans.push_back(i.first);
            }
        }
        return ans;
        
    }
};