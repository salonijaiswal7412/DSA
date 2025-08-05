//memoization
class Solution {
public:
    int f(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int ans=1e9;
        for(int k=i;k<=j;k++){
            int t=cuts[j+1]-cuts[i-1]+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
            ans=min(ans,t);
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return f(1,m-2,cuts,dp);

        
    }
};

//tabulation
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,0));

        for(int i=m-2;i>=1;i--){
            for(int j=1;j<=m-2;j++){
                if(i>j) continue;
                int ans=1e9;
                for(int k=i;k<=j;k++){
                    int t=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    ans=min(ans,t);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][m-2];
        
    }
};
