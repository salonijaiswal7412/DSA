//memoization leads to tle
class Solution {
public:
    int f(int i,int j,int n,vector<vector<int>>& a,vector<vector<int>>& dp){
        
        if(j<0 || j>n-1) return 1e9;
        if(i==0) return a[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int u=a[i][j]+f(i-1,j,n,a,dp);
        int l=a[i][j]+f(i-1,j-1,n,a,dp);
        int r=a[i][j]+f(i-1,j+1,n,a,dp);

        return dp[i][j]=min(u,min(r,l));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            int temp=f(n-1,i,n,matrix,dp);
            ans=min(ans,temp);
        }
        return ans;
        
    }
};

//tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int n=m.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[0][i]=m[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int l,r;
                int u=m[i][j]+dp[i-1][j];
                if(j>0)
                l=m[i][j]+dp[i-1][j-1];
                else l=1e9;
                if(j<n-1)
                 r=m[i][j]+dp[i-1][j+1];
                else  r=1e9;

                dp[i][j]=min(u,min(l,r));
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
        
    }
};
//space optimized code
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int n=m.size();
        vector<int>prev(n);vector<int>curr(n);
        for(int i=0;i<n;i++){
            prev[i]=m[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int l,r;
                int u=m[i][j]+prev[j];
                if(j>0)
                l=m[i][j]+prev[j-1];
                else l=1e9;
                if(j<n-1)
                 r=m[i][j]+prev[j+1];
                else  r=1e9;

                curr[j]=min(u,min(l,r));
            }
            prev=curr;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,prev[i]);
        }
        return ans;
        
    }
};
