class Solution {
public:
    int maxPower(string s) {
        int c=1,ans=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1])c++;
            else{
                ans=max(ans,c);
                c=1;
            }
        }
        return max(c,ans);
        
    }
};