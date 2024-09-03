class Solution {
public:
    int getLucky(string s, int k) {
        string n="";
        for(char x: s){
            n+=to_string(x-'a'+1);
        }
        while(k!=0){
            int t=0;
            for(char x:n){
                t+=x-'0';
            }
            n=to_string(t);
            k--;
        }
        return stoi(n);
        
    }
};