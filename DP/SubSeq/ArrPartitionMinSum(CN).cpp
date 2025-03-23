int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int s=0;
	for(auto i: arr) s+=i;
	int k=s;
	vector<vector<bool>> dp(n,vector<bool> (k+1,false));
	for(int i=0;i<n;i++){
		dp[i][0]=true;
	}
	if(arr[0]<=k) dp[0][arr[0]]=true;
	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
			bool nottake=dp[i-1][j];
			bool take=false;
			if(arr[i]<=j){
				take=dp[i-1][j-arr[i]];
			}
			dp[i][j]=take|nottake;
		}
	}
	int ans=1e9;
	for(int i=0;i<=k;i++){
		if(dp[n-1][i]==true){
			ans=min(ans,abs((k-i)-i));
		}
	}
	return ans;

}
