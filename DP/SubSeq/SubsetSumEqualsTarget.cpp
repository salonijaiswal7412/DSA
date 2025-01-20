//memoization
// User function template for C++

class Solution {
  public:
    bool f(int i,int target,vector<int>& arr,vector<vector<int>>& dp){
        if(target==0) return true;
        if(i==0) return (target==arr[0]);
        
       
      if(dp[i][target]!=-1) return dp[i][target];
        bool NotTake=f(i-1,target,arr,dp);
        bool Take=false;
        if(arr[i]<=target)
        Take=f(i-1,target-arr[i],arr,dp);
        
        return dp[i][target]=Take|NotTake;
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,arr,dp);
    }
};
//tabulation
// User function template for C++

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(target+1,0));
        
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        dp[0][arr[0]]=true;
        
        for(int i=1;i<n;i++){
            for(int k=1;k<=target;k++){
                bool notTake=dp[i-1][k];
                bool take=false;
                if(arr[i]<=k)take=dp[i-1][k-arr[i]];
                
                dp[i][k]=take|notTake;
            }
        }
        return dp[n-1][target];
    }
};
//space optimization
// User function template for C++

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<bool> prev(target+1,0),curr(target+1,0);
        
        prev[0]=curr[0]=true;
        if(arr[0]<=target) prev[arr[0]]=true;
        
        for(int i=1;i<n;i++){
            for(int k=1;k<=target;k++){
                bool notTake=prev[k];
                bool take=false;
                if(arr[i]<=k)take=prev[k-arr[i]];
                
                curr[k]=take||notTake;
            }
            prev=curr;
        }
        return prev[target];
    }
};

