//memoization
class Solution {
public:
    int f(int i,int prev,vector<int>& nums,vector<vector<int>>& dp){
        if(i==nums.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
       int nt=0+f(i+1,prev,nums,dp);
       int t=0;
       if(prev==-1 || nums[prev]<nums[i]){
        t=1+f(i+1,i,nums,dp);
       }
       return dp[i][prev+1]=max(t,nt);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
        
    }
};

//tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int nt=dp[i+1][prev+1];
                int t=0;
                if(prev==-1 || nums[i]>nums[prev]){
                    t=1+dp[i+1][i+1];
                }
                dp[i][prev+1]=max(t,nt);
            }
            
        }
        return dp[0][0];
        
    }
};
