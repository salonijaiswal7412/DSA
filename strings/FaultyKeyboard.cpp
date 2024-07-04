class Solution {
public:
    
    string finalString(string s) {
        string n="";
        for(char i : s){
            if(i!='i')
            n+=i;
            else
            reverse(n.begin(),n.end());
        }
        return n;
        
    }
};
