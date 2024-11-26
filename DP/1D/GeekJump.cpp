//memoization
class Solution {
  public:
    int jump(vector<int>& h,int i,vector<int>& dp){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int l=jump(h,i-1,dp)+abs(h[i]-h[i-1]);
        int r=INT_MAX;
        if(i>1) r=jump(h,i-2,dp)+(abs(h[i]-h[i-2]));
        return dp[i]=min(l,r);
        
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1,-1);
        return jump(height,n-1,dp);
    }
};

//Tabulation
class Solution {
  public:
    int minimumEnergy(vector<int>& h, int n) {
        
        // Code here
        vector<int> dp(n,0);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int l=dp[i-1]+abs(h[i]-h[i-1]);
            int r=INT_MAX;
            if(i>1){
                r=dp[i-2]+abs(h[i]-h[i-2]);
            }
            dp[i]=min(l,r);
        }
        return dp[n-1];
        
    }
};
//space efficient 
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        int prev=0,prev2=0;
        for(int i=1;i<n;i++){
            int l=prev+abs(height[i]-height[i-1]);
            int r=INT_MAX;
            if(i>1){
                r=prev2+abs(height[i]-height[i-2]);
            }
            int curr=min(l,r);
            prev2=prev;
            prev=curr;
        }
        return prev;
        // Code here
    }
};
