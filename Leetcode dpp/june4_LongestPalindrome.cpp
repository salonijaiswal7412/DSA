class Solution {
public:
    int longestPalindrome(string s) {
        int oddC=0;
        unordered_map<char,int> freq;
        for(char ch: s){
            freq[ch]++;
            if(freq[ch]%2==1) oddC++;
            else oddC--;
        }
        if(oddC>1){
            return s.length()-oddC+1;

        }
        return s.length();
        
    }
};
