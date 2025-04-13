//using merge sort
#include <bits/stdc++.h> 
long long merge(int l,int mid,int h,long long* arr){
    int m=mid-l+1;
    int n=h-mid;
    vector<int> left(m,0),right(n,0);
    long long c=0;
    for(int i=0;i<m;i++){

        left[i]=arr[l+i];
    }
    for(int i=0;i<n;i++){
        right[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<m && j<n){
        if(left[i]<=right[j]){
            arr[k++]=left[i++];
        }
        else{
            c+=m-i;
            arr[k++]=right[j++];
        }
    }
    while(i<m) arr[k++]=left[i++];
    while(j<n) arr[k++]=right[j++];
    return c;
}
long long mergesort(int l,int h,long long* arr){
    long long c=0;
    if(l<h){
        
        int m=(l+h)/2;
        c+=mergesort(l,m,arr);
        c+=mergesort(m+1,h,arr);
        c+=merge(l,m,h,arr);
    }
    return c;
}
long long getInversions(long long *arr, int n){
    return mergesort(0,n-1,arr);
    // Write your code here.
}
