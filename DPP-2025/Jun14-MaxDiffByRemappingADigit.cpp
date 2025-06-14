class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        string max=s,min=s;
        for(char& i:s){
            if(i!='9'){
                for(char& c:max){
                    if(c==i){
                        c='9';
                    }
                }
                break;
            }
        }
        for(char& i:s){
            if(i!='0'){
                for(char& c:min){
                    if(c==i){
                        c='0';
                    }
                }
                break;
            }
        }
        return stoi(max)-stoi(min);
        
        
    }
};
