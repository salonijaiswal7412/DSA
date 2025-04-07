class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(auto i:nums) s+=i;
        if(s%2) return false;
        int k=s/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=k){
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                bool nt=dp[i-1][j];
                bool t=false;
                if(nums[i]<=j){
                    t=dp[i-1][j-nums[i]];
                }
                dp[i][j]=t|nt;
            }
        }
        return dp[n-1][k];
        
    }
};
