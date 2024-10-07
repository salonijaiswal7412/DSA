class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(st.empty()){
                st.push(c);
                continue;
            }
            if(c=='B' && st.top()=='A') st.pop();
            else if(c=='D' && st.top()=='C') st.pop();
            else st.push(c);
        }
        return st.size();
        
    }
};