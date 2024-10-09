class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        for(auto i:s){
            if(st.empty()) st.push(i);
            else{
                if(i=='('||(i==')' && st.top()!='('))
                st.push(i);
                else st.pop();
            }
            
        }
        return st.size();
        
    }
};