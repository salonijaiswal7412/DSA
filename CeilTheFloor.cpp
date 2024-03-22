pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int ceil=-1,floor=-1,l=0,r=n-1,mid;
	while(l<=r){
		//floor
		mid=(l+r)/2;
		if(x>=a[mid]){
			floor=a[mid];
			l=mid+1;
		}
		if(x<=a[mid]){
			ceil=a[mid];
			r=mid-1;
		}
	}
	pair<int,int> p;
	p.first=floor;
	p.second=ceil;
	return p;
}
