class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char,int> m;
        for(char c:s){
            m[c]++;
        }

        stack<char> st;
        string ans;
        char min='a';
        for(char i:s){
            st.emplace(i);
            m[i]--;
            while(min!='z' && m[min]==0){
                min++;
            }
            while(!st.empty() && st.top()<=min){
                ans.push_back(st.top());
                st.pop();
            }

        }
        return ans;
    }
};
