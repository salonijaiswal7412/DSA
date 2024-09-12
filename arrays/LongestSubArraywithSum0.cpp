#include<bits/stdc++.h>
//approach using hashmap

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	// Write your code here.
	unordered_map<int,int> m;
	int maxl=0,s=0;

	for(int i=0;i<arr.size();i++){
		s+=arr[i];
		if(s==0){
			maxl=i+1;
		}
		if(m.find(s)!=m.end()){
			maxl=max(maxl,i-m[s]);
		}else{
			m[s]=i;
		}
	}
	return maxl;
	
}