class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int x=1000;
        int ans=0;

        while(x!=0){
            ans=ans*10+min(num1/x,min(num2/x,num3/x));
            num1%=x;
            num2%=x;
            num3%=x;

            x/=10;

        }
        return ans;
        
    }
};