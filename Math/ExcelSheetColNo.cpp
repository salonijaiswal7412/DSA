class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=0;
        for(char c:columnTitle){
            int x=(c-'A'+1);
            n=n*26+x;
            
        }
        return n;
        
    }
};