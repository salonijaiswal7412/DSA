class Solution {
public:
    int findComplement(int n) {
        string s;
        while(n!=0){
            if(n%2==0) s='1'+s;
            else s='0'+s;
            n/=2;
        }
        int p=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1')n+=pow(2,p);
            p++;
        }
        return n;
        
    }
};
