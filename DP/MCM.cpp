//memoization
#include <bits/stdc++.h> 

int f(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=1e9;
    for(int k=i;k<j;k++){
        int steps=(arr[i-1]*arr[j]*arr[k])+f(i,k,arr,dp)+f(k+1,j,arr,dp);
        ans=min(ans,steps);
    }
    return dp[i][j]=ans;

}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N,vector<int>(N,-1));
    return f(1,N-1,arr,dp);
}

//tabulation
#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N,vector<int>(N,0));

    for(int i=N-1;i>0;i--){
        for(int j=i+1;j<N;j++){
            int ans=1e9;
            for(int k=i;k<j;k++){
                int steps=(arr[i-1]*arr[j]*arr[k])+dp[i][k]+dp[k+1][j];
                ans=min(ans,steps);
            }
            dp[i][j]=ans;
        }
    }
    return dp[1][N-1];
}
