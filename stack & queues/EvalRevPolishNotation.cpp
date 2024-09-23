class Solution {
public:
    int evalRPN(vector<string>& t) {
        int ans=0;
        stack<int> s;
        for(auto i:t){
            if(i=="+"||i=="-"||i=="*"||i=="/"){
                int a=s.top();s.pop();
                int b=s.top();s.pop();
                int c=((i=="+")?(b+a):((i=="-")?(b-a):((i=="*")?(b*a):(b/a))));
                s.push(c);
            }
            else{
                s.push(stoi(i));
            }
        }
        return s.top();
    }
};