//tabulation
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=1;dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n]; 
        
    }
};
//space efficient
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;
        
        int a=1,b=1,c;
        for(int i=2;i<=n;i++){
            c=a+b;
            a=b;b=c;
        }
        return c;
        
    }
};