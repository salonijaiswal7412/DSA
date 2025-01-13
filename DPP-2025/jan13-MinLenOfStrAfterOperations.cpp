class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> m;
        for(auto i:s){
            m[i]++;
        }
        int ans=0;
        for(auto [ch,freq]:m){
            while(m[ch]>=3) m[ch]-=2;

            ans+=m[ch];
        }
        
        
        return ans;
        
    }
};
