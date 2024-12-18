//memoization
class Solution {
  public:
    int f(int i,int j1,int j2,int r,int c,vector<vector<int>>& a,vector<vector<vector<int>>>& dp){
        if(j1<0 || j2<0 || j1>=c || j2>=c){
            return -1e9;
        }
        if(i==r-1){
            if(j1==j2) return a[i][j1];
            else return a[i][j1]+a[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        
        int maxi=-1e9;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int v=0;
                if(j1==j2) v=a[i][j1];
                else v=a[i][j1]+a[i][j2];
                v+=f(i+1,j1+dj1,j2+dj2,r,c,a,dp);
                maxi=max(v,maxi);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int solve(int r, int c, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>>dp (r,vector<vector<int>>(c,vector<int>(c,-1)));
        return f(0,0,c-1,r,c,grid,dp);
    }
};
//tabulation
