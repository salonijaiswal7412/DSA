class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> diff(n+1,0);
        for(auto q:queries){
            diff[q[0]]-=1;
            diff[q[1]+1]+=1;

        }
        int s=0;
        for(int i=0;i<n;i++){
            s+=diff[i];
            diff[i]=s;
        }
        for(int i=0;i<n;i++){
            nums[i]+=diff[i];
            if(nums[i]>0) return false;
        }
        return true;
        
    }
};
