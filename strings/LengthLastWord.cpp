
class Solution {
public:
    int lengthOfLastWord(string s) {
        int l=0;
        bool flag=false;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!=' '){
                flag=true;
                l++;
            }
            else if(flag){
                break;
            }
        }
        return l;
        
    }
};
