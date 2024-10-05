class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m=s.length();
        int n=p.length();
        if(n>m) return {};

        vector<int> a(26,0),b(26,0);
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
            b[p[i]-'a']++;
        }
        vector<int> ans;
        if(a==b ) ans.push_back(0);
        for(int i=n;i<m;i++){
            a[s[i-n]-'a']--;
            a[s[i]-'a']++;
            if(a==b) ans.push_back(i-n+1);
        }
        return ans;
        
    }
};