//approach1
class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int n=s.size(),c=1;
        ans.push_back(s[0]);
        for(int i=1;i<n;i++){
            if(s[i]==ans.back()){
                c++;
                if(c<3) ans.push_back(s[i]);
            }
            else{
                c=1;
                ans.push_back(s[i]);
            }
        }
        return ans;
        
    }
};
//approach 2- space efficient
class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size(),i=0;
        char prev=' ';
        for(int l=0;char ch:s){
            if(prev!=ch) l=1;
            else l++;
            if(l<=2)
            s[i++]=ch;
            prev=ch;
        }
        s.resize(i);
        return s;

        
    }
};
