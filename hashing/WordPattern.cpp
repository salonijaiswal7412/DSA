class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string temp;
        vector<string>ss;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                temp.push_back(s[i]);
            }
            else if(s[i]==' '){
                if(!temp.empty()){
                    ss.push_back(temp);
                    temp.clear();
                }
            }
        }
        if(!temp.empty()){
            ss.push_back(temp);

        }

        map<char,string>m1;
        map<string,char>m2;

        if(pattern.length()!=ss.size()) return false;
         for(int i=0;i<pattern.length();i++){
            char ch=pattern[i];
            string w=ss[i];

            if(m1.find(ch)!=m1.end()){
                if(m1[ch]!=w) return false;
            }
            else{
                m1[ch]=w;
            }

            if(m2.find(w)!=m2.end()){
                if(m2[w]!=ch) return false;
            }
            else{
                m2[w]=ch;
            }
         }
        return true;
    }
    
};
