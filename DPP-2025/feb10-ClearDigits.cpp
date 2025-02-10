//my approach
class Solution {
public:
    string clearDigits(string str) {
        stack<char> s;
        for(auto i: str){
            if(i>='0' && i<='9'){
                if(!s.empty()) s.pop();
                continue;
            }
            else 
            s.push(i);
        }
        string ans;
        while(!s.empty()){
            ans=s.top()+ans;
            s.pop();
        }
        return ans;
        
    }
};
