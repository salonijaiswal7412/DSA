class Solution {
public:
    bool canChange(string s, string t) {
        int i=0,j=0,n=s.size();
        while(i<n || j<n){
            while(i<n && s[i]=='_') i++;
            while(j<n && t[j]=='_') j++;

            if(i==n|| j==n) break;
            if(s[i]!=t[j]) return false;
            if(s[i]=='L')
            if(i<j) return false;
            if(s[i]=='R')
            if(i>j) return false;
            i++;j++;
        }
        return i==n && j==n;
        
    }
};
