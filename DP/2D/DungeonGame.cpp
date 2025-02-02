class Solution {
public:
    int solve(vector<vector<int>>& arr,vector<vector<int>>& dp,int i=0,int j=0){
        int m=arr.size();
        int n=arr[0].size();

        if(i==m || j==n) return 1e9;
        if(i==m-1 && j==n-1) return (arr[i][j]<=0)?1-arr[i][j]:1;
        if(dp[i][j]!=1e9) return dp[i][j];

        int r=solve(arr,dp,i,j+1);
        int d=solve(arr,dp,i+1,j);

        int ans=min(r,d)-arr[i][j];

        return dp[i][j]=(ans<=0)?1:ans;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();

        vector<vector<int>> dp(m,vector<int>(n,1e9));

        return solve(dungeon,dp);
        
    }
};
