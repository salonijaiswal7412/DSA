#include<vector>

int getSingleElement(vector<int> &arr){
	// Write your code here.
	int c=0;	
	for(int i=0;i<arr.size();i+=2){
		if(arr[i]==arr[i+1])
		c++;
		else
		return arr[i];
	}
	return arr[c];
}
