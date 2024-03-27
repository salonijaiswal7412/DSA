int func(int mid,int n,int m){
  long long ans=1;
  for(int i=1;i<=n;i++){
    ans*=mid;
    if(ans>m)return 2;
  }
  if(ans==m)return 1;
  else return 0;
}
int NthRoot(int n, int m) {
  // Write your code here.
  int l=1,h=m,mid;
  while(l<=h){
    mid=l+(h-l)/2;
    int v=func(mid,n,m);
    if(v==1)
    return mid;
    else if(v==0)
    l=mid+1;
    else if(v==2)
    h=mid-1;
  }
  return -1;
}
