class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int n=s.size();
        for(int i=0;i<n;i++){
            s+=s[i];
            if(s.substr(i+1,n+1)==goal) return true;
        }
        return false;

        
    }
};
