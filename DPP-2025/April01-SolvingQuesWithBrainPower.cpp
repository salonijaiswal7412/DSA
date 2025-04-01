//memoization
class Solution {
public:
    long long f(int i,vector<long long>& dp,vector<vector<int>>& ques){
        int n=ques.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long nt=f(i+1,dp,ques);
        long long t=ques[i][0]+f(i+ques[i][1]+1,dp,ques);
        return dp[i]=max(nt,t);
       
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,-1);
        return f(0,dp,questions);
    }
};

//tabulation
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            long long nt=dp[i+1];
            long long t=questions[i][0];
            if(questions[i][1]+1+i<n){
                t+=dp[questions[i][1]+1+i];
            }
            dp[i]=max(t,nt);
        }
        return dp[0];
        
    }
};
