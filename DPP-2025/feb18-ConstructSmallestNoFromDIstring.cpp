class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int>s;
        int n=pattern.length();
        string ans="";
        for(int i=1;i<=n+1;i++){
            s.push(i);
            if(i-1==n || pattern[i-1]=='I'){
                while(!s.empty()){
                    ans+=to_string(s.top());
                    s.pop();
                }
            }
        }
        return ans;
        
    }
};
