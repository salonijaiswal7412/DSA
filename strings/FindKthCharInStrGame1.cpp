class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            string temp="";
            for(int i=0;i<s.size();i++){
                if(s[i]=='z'){
                temp+="a";
                continue;
            }
            else{
                temp+=s[i]+1;
            }
            }
            s+=temp;
        }
        return s[k-1];
        
    }
};
