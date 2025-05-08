//cn
string findLCS(int m, int n,string &s1, string &s2){
	// Write your code here.	
	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int len=dp[m][n];
	string ans="";
	for(int i=0;i<len;i++) ans+=".";
	int idx=len-1;
	int i=m,j=n;
	while(i>0 && j>0){
		if(s1[i-1]==s2[j-1]){
			ans[idx--]=s1[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1]){
			i--;
		}
		else {
			j--;
		}
	}
	return ans;

}
