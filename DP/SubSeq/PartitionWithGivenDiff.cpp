//memoization
class Solution {
  public:
    int mod=1e9+7;
    int f(int i,int k,vector<int>& arr,vector<vector<int>>& dp){
        if(i==0){
            if(arr[0]==0 && k==0) return 2;
            if(arr[0]==k || k==0) return 1;
            return 0;
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int notpick=f(i-1,k,arr,dp);
        int pick=0;
        if(arr[i]<=k) pick=f(i-1,k-arr[i],arr,dp);
        
        return dp[i][k]=(pick+notpick)%mod;
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n=arr.size();
        int s=0;
        for(int i:arr) s+=i;
        if((s-d)<0 || (s-d)%2) return 0;
        vector<vector<int>> dp(n,vector<int>(((s-d)/2)+1,-1));
        return f(n-1,(s-d)/2,arr,dp);
    }
};
//tabulation
class Solution {
  public:
  int mod=1e9+7;
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n=arr.size();
        int s=0;
        for(int i: arr)s+=i;
        if(s-d<0 ||(s-d)%2) return 0;
        int k=(s-d)/2;
        vector<vector<int>> dp(n,vector<int>(k+1,0));
        if(arr[0]==0){
            dp[0][0]=2;
        }
        else dp[0][0]=1;
        
        if(arr[0]!=0 && arr[0]<=k) dp[0][arr[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=k;j++){
                int notpick=dp[i-1][j];
                int pick=0;
                if(arr[i]<=j){
                    pick=dp[i-1][j-arr[i]];
                }
                dp[i][j]=(pick+notpick)%mod;
            }
        }
        return dp[n-1][k];
    }
};
