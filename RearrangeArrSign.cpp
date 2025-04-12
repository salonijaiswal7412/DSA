class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,0);
        
        int pos=0;int neg=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0){
                v[neg]=nums[i];
                neg+=2;
            }
            else if(nums[i]>0){
                v[pos]=nums[i]; 
                pos+=2;
            }
        }
        return v;
        
    
};
