class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int c=0;
        for(char ch:s){
            if(ch=='(' && c++>0){
                ans+=ch;
            }
            if(ch==')' && c-->1){
                ans+=ch;
            }
        }
        return ans;
    }
};
