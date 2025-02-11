class Solution {
public:
    bool check(stack<char>& s,string part,int p ){
        stack<char> temp=s;
        for(int i=p-1;i>=0;i--){
            if(temp.top()!=part[i]) return false;
            temp.pop();
        }
        return true;
    }
    string removeOccurrences(string str, string part) {
        stack<char> s;
        int n=str.length(),p=part.length();

        for(int i=0;i<n;i++){
            s.push(str[i]);
            if(s.size()>=p && check(s,part,p)){
                for(int j=0;j<p;j++)
                s.pop();
            }
        }
        string ans="";
        while(!s.empty()){
            ans=s.top()+ans;
            s.pop();
        }
        return ans;
        
    }
};
