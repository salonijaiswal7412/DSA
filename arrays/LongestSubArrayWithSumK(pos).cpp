//approach using hashmap this is optimal for pos+neg
#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    map<long long,int> m;
    int maxl=0;
    long long s=0;
    int n=a.size();

    for(int i=0;i<n;i++){
        s+=a[i];
        if(s==k){
            maxl=i+1;
        }
        long long rem=s-k;
        if(m.find(rem)!=m.end()){
            maxl=max(maxl,i-m[rem]);
        }
        if(m.find(s)==m.end()){
            m[s]=i;
        }
    }
    return maxl;
}

//using two pointer approach
int l=0,r=0,maxl=0;
        long long s=A[0];
        while(r<N){
            while(s>K && l<=r){
                s-=A[l++];
            }
            if(s==K) maxl=max(maxl,r-l+1);
            r++;
            if(r<N){
                s+=A[r];
            }
        }
        return maxl;