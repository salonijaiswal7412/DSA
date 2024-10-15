class Solution {
public:
    long long minimumSteps(string s) {
        int l=0,r=s.length()-1;
        long long ans=0;
        while(l<=r){
            if(s[l]=='1' && s[r]=='0'){
                ans+=r-l;
                l++;
                r--;
            }
            else if(s[l]=='0')l++;
            else if(s[r]=='1')r--;
        }
        return ans;
        
        
    }
};