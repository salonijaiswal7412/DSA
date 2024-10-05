class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        if(m>n) return false;
        vector<int> a(26,0),b(26,0);

        for(int i=0;i<m;i++){
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        }

        for(int i=0;i<n-m;i++){
            if(a==b) return true;

            b[s2[i]-'a']--;
            b[s2[i+m]-'a']++;
        }
        return(a==b);
        
    }
};