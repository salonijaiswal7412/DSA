class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int c=1;
        for(int i=1;i<=word.size();i++){
            if(i==word.size()|| word[i]!=word[i-1]|| c==9){
                ans+=to_string(c)+word[i-1];
                c=1;
            }
            else{
                c++;
            }
        }
        return ans;
        
    }
};
