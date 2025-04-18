//recursion
class Solution {
public:
    string helper(string s){
       
        string ans="";
        for(int i=0;i<s.size();i++){
            int c=1;
            while(i<s.size() && s[i]==s[i+1]){
                i++;c++;
            }
            ans+=to_string(c)+s[i];

        }
       
        return ans;
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        return helper(countAndSay(n-1));


        
    }
};
//iterative
class Solution {
public:
    string helper(string s){
        string res="";
        for(int i=0;i<s.size();i++){
            int c=1;
            while(i<s.size()-1 && s[i]==s[i+1]){
                i++;
                c++;
            }
            res+=to_string(c)+s[i];
        }
        return res;
    }
    string countAndSay(int n) {
        string ans="1";
        for(int i=2;i<=n;i++){
            ans=helper(ans);
        }
        return ans;
        
    }
};
