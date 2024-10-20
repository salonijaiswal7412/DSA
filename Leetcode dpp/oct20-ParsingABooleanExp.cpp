class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        for(char i:expression){
            if(i==')'){
                vector<char> sub;
                while(s.top()!='('){
                    sub.push_back(s.top());
                    s.pop();
                }
                s.pop();

                char op=s.top();
                s.pop();
                if(op=='!'){
                    s.push(sub[0]=='t'?'f':'t');
                }
                else if(op=='&'){
                    char res='t';
                    for(char c:sub){
                        if(c=='f'){
                            res='f';
                            break;
                        }
                    }
                    s.push(res);
                }
                else if(op=='|'){
                    char res='f';
                    for(char c:sub){
                        if(c=='t'){
                            res='t';
                            break;
                        }
                    }
                    s.push(res);
                }
            }
            else if(i!=','){
                s.push(i);
            }
        }
        return s.top()=='t';
        
    }
};
