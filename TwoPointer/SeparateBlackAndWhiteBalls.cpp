class Solution {
public:
    long long minimumSteps(string s) {
        int l=0;
        int r=s.size()-1;
        long long c=0;
        while(l<=r){
            if(s[l]=='1' && s[r]=='0'){
                c+=r-l;
                l++;r--;
            }
            if(s[l]=='0')l++;
            if(s[r]=='1')r--;
        }
        return c;
        
    }
};