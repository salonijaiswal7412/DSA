class Solution {
public:
    int minSwaps(string s) {
        int c=0,imbalance=0;
        for(char i:s){
            if(i==']'){
                if(imbalance==0){
                    c++;imbalance++;
                }
                else imbalance--;
            }
            else imbalance++;
        }
        return c;
        
    }
};