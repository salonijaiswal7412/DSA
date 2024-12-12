//recursion
class Solution {
public:
    int f(int i,vector<int>& nums){
        if(i==0) return nums[i];
        if(i<0) return 0;
        int pick=nums[i]+f(i-2,nums);
        int notpick=0+f(i-1,nums);
        return max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        return f(n-1,nums);
        
    }
};

//memoization
class Solution {
public:
    int solve(int i,vector<int>& nums,vector<int>& dp){
        if(i==0) return nums[0];
        if(i<0) return 0;

        if(dp[i]!=-1) return dp[i];

        int p=nums[i]+solve(i-2,nums,dp);
        int np=0+solve(i-1,nums,dp);

        return dp[i]=max(p,np);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,nums,dp);
        
    }
};

//tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int p=nums[i];
            if(i>1) p+=dp[i-2];
            int np=dp[i-1];

            dp[i]=max(p,np);
        }
        return dp[n-1];
        
    }
};

//space optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
       
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int p=nums[i];
            if(i>1) p+=prev2;
            int np=prev;

            int curr=max(p,np);
            prev2=prev;
            prev=curr;
        }
        return prev;
        
    }
};
