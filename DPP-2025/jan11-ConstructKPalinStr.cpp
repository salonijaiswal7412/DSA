class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        if(s.length()==k) return true;

        vector<int> freq(26);
        int odd=0;
        for(char i:s){
            freq[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]%2!=0) odd++;
        }
        return (odd<=k);
        
    }
};
