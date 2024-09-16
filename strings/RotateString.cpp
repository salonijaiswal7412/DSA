class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
        int l=s.length();
        for(int i=0;i<l;i++){
            s+=s[i];
            string sub=s.substr(i+1,l+1);
            if(sub==goal) return true;
        }
        return false;
        
        
    }
};