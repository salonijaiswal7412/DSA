void sum(int idx,int s,vector<int>& a,vector<int>& ans){
	if(idx==a.size()){
		ans.push_back(s);
		return;
	}
	sum(idx+1,s+a[idx],a,ans);
	sum(idx+1,s,a,ans);
}
vector<int> subsetSum(vector<int> &num){
	// Write your code here.	
	vector<int> ans;
	sum(0,0,num,ans);
	sort(ans.begin(),ans.end());
	return ans;
}