//memoization
class Solution {
public:
int f(int i,int k,int n,vector<int>& arr,vector<int>& dp){
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans=-1e9,maxel=-1e9,len=0;

    for(int j=i;j<min(n,i+k);j++){
        len++;
        maxel=max(maxel,arr[j]);
        int t=maxel*len+f(j+1,k,n,arr,dp);
        ans=max(ans,t);
    }
    return dp[i]=ans;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return f(0,k,n,arr,dp);
        
    }
};
//tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int len=0,maxel=-1e9,ans=-1e9;
            for(int j=i;j<min(n,i+k);j++){
                len++;
                maxel=max(maxel,arr[j]);
                int t=maxel*len+dp[j+1];
                ans=max(t,ans);
            }
            dp[i]=ans;
        }
        return dp[0];
        
    }
};
