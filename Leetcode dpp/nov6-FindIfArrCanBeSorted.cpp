class Solution {

public:
    int countBits(int n){
        return bitset<32>(n).count();
    }
    bool canSortArray(vector<int>& nums) {
        int pre=INT_MIN;
        int currmax=nums[0];
        int currmin=nums[0];
        int setbits=countBits(nums[0]);
        for(size_t i=1;i<nums.size();i++){
            if(setbits==countBits(nums[i])){
                currmax=max(currmax,nums[i]);
                currmin=min(currmin,nums[i]);

            }
            else{
                if(currmin<pre){
                    return false;
                }

                pre=currmax;
                setbits=countBits(nums[i]);
                currmin=nums[i];
                currmax=nums[i];
            }
        }
        return currmin>pre;
        
    }
};
