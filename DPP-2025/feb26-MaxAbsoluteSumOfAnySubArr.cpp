class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int a=0,b=0;
        int s=0;
        for(auto i:nums){
            s+=i;
            if(s>0){
                a=max(s,a);
            }
            else{
                s=0;
            }
        }
        s=0;
        for(auto i:nums){
            s+=i;
            if(s<0){
                b=min(b,s);
            }
            else s=0;
        }
       
        return (max(a,abs(b)));

        
    }
};
