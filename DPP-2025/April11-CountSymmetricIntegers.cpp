class Solution {
public:
    
    bool check(int n){
        string s=to_string(n);
        int d=s.size();
        if(d%2) return false;

        int s1=0,s2=0;
        for(int i=0;i<d/2;i++){
            s1+=(s[i]-'0');
            s2+=(s[d/2+i]-'0');
        }
        return s1==s2;
        
    }
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            if(check(i)){
                ans++;
            }
        }
        return ans;
        
    }
};
