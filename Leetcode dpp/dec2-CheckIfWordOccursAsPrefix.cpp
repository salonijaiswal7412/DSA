//using stringstream
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=searchWord.length();
        stringstream s(sentence);
        string word;
        int idx=0;
        while(s>> word){
            idx++;
            if(word.length()<n) continue;
            if(word.substr(0,n)==searchWord) return idx;
            
        }
        return -1;
    }
};
