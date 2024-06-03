class Solution {
public:
    string largestOddNumber(string num) {
        int j=num.length()-1;
        while(j>=0){
            if(num[j]%2==1){
                return num.substr(0,j+1);
            }
            j--;
        }
        return "";
    }
};
