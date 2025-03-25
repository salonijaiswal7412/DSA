//this question is basically like subset sum equal to atrget only ,first we have to find the total sum of the array and if its odd return false and then proceed to find a subset with half the sum and if found return true as s/2 becomes the target.
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s=0;
        int n=nums.size();
        for(auto i: nums) s+=i;
        if(s%2) return false;
        int k=s/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=k)
        dp[0][nums[0]]=true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                bool nottake=dp[i-1][j];
                bool take=false;
                if(nums[i]<=j)
                take=dp[i-1][j-nums[i]];

                dp[i][j]=take| nottake;
            }
        }
        return dp[n-1][k];
        
    }
}; 

