class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign=1;
        long long int ans=0;
        while(i<s.length() && s[i]==' ')i++;
        if(i<s.length() && (s[i]=='+' || s[i]=='-')){
            sign=(s[i]=='+')?1:-1;
            i++;
        }
        while(i<s.length() && isdigit(s[i])){
            ans=ans*10+(s[i]-'0');
            if(ans*sign<=INT_MIN) return INT_MIN;
            if(ans*sign>=INT_MAX) return INT_MAX;
            i++;
        }
        return ans*sign;
        
    }
};