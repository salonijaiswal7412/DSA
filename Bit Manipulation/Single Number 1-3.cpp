//single number 1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto i:nums){
            ans^=i;
        }
        return ans;
        
    }
};

//single number 2
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,twos=0;
        for(int i=0;i<nums.size();i++){
            ones=(ones^nums[i])&(~twos);
            twos=(twos^nums[i])&(~ones);
        }
        return ones;
        
    }
};

//single number 3
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorr=0;
        for(int i:nums) xorr^=i;

        int right=(xorr & (xorr-1))^ xorr;

        int b1=0,b2=0;
        for(int i:nums){
            if(i& right){
                b1=b1^i;
            }
            else{
                b2=b2^i;
            }
        }
        return {b1,b2};
        
    }
};
