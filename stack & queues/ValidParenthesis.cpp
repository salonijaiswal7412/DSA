class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(char i:str){
            if(i=='{'||i=='['||i=='(')
            s.push(i);
            else if(s.empty()) return false;
            else{
                if(i==')'){
                    if(s.top()!='(')
                    return false;
                }
                if(i=='}'){
                    if(s.top()!='{')
                    return false;
                }
                if(i==']'){
                    if(s.top()!='[')
                    return false;
                }
                s.pop();
            }
        }
        if(s.empty())
        return true;
        else return false;
    }
};