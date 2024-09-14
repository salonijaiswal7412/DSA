class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        unordered_set<char> st;
        int l=0;
        for(int r=0;r<s.length();r++){
            if(st.count(s[r])==0){
                st.insert(s[r]);
                ans=max(ans,r-l+1);
            }
            else{
                while(st.count(s[r])){
                    st.erase(s[l++]);
                }
                st.insert(s[r]);
            }
        }
        return ans;
        
    }
};