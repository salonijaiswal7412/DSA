class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int el,c=0,n=nums.size();
        for(int i:nums){
            if(c==0){
                el=i;
                c++;
            }
            else{
                if(i==el) c++;
                else c--;
            }
        }
        c=0;
        for(int i:nums){
            if(i==el) c++;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el) cnt++;
            int rem=c-cnt;
            if(cnt*2>1+i && rem*2>n-i-1){
                return i;
            }
        }
        return -1;


        
    }
};
