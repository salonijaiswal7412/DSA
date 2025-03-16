//memoization
class Solution {
public:
    int solve(int i,vector<int>& a,vector<int>& dp){
        if(i==0) return a[0];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int p=a[i]+solve(i-2,a,dp);
        int np=solve(i-1,a,dp);
        return dp[i]=max(p,np);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> a(nums.begin()+1,nums.end());
        vector<int> b(nums.begin(),nums.end()-1);
        vector<int> dp1(n,-1),dp2(n,-1);
        return max(solve(a.size()-1,a,dp1),solve(b.size()-1,b,dp2));
        
    }
};
//space optimised
class Solution {
public:
    int f(vector<int>& nums){
        int n=nums.size();
        int prev=nums[0],prev2=0;
        for(int i=1;i<n;i++){
            int p=nums[i];
            if(i>1) p+=prev2;
            int np=prev;
            int curr=max(p,np);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> a,b;
        for(int i=0;i<n;i++){
            if(i!=0) a.push_back(nums[i]);
            if(i!=(n-1)) b.push_back(nums[i]);
        }
        return max(f(a),f(b));
        
        
    }
};
