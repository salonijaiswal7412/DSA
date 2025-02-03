//memoization
#include <bits/stdc++.h> 
int solve(vector<int> w,vector<int> v,int i,int W,vector<vector<int>>& dp){
	if(i==0){
		if(w[0]<=W) return v[0];
		else return 0;
	}
	if(dp[i][W]!=-1) return dp[i][W];

	int nottake=0+solve(w,v,i-1,W,dp);
	int take=-1e9;
	if(w[i]<=W){
		take=v[i]+solve(w,v,i-1,W-w[i],dp);
	}
	return dp[i][W]=max(take,nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return solve(weight,value,n-1,maxWeight,dp);
}

//tabulation
#include <bits/stdc++.h> 
int knapsack(vector<int> w, vector<int> v, int n, int W) 
{
	// Write your code here
	vector<vector<int>> dp(n,vector<int>(W+1,0));
	for(int wt=w[0];wt<=W;wt++){
		dp[0][wt]=v[0];
	}

	for(int i=1;i<n;i++){
		for(int wt=0;wt<=W;wt++){
			int nottake=0+dp[i-1][wt];
			int take=-1e9;
			if(w[i]<=wt){
				take=v[i]+dp[i-1][wt-w[i]];
			}

			dp[i][wt]=max(take,nottake);
		}
	}
	return dp[n-1][W];
}
