class Solution {
public:
    bool possible(vector<int>v ,int day,int m,int k){
        int B=0,c=0;
        for(int i=0;i<v.size();i++){
            if(v[i]<=day){
                c++;
            }
            else{
                B+=(c/k);
                c=0;
            }
        }
        B+=(c/k);
        return B>=m;
    }
    int minDays(vector<int>& v, int m, int k) {
        int n=v.size();
        long long val=m*1ll*k*1ll;
        if(val>n)return -1;
        int mini=v[0],maxi=v[0];
        for(int i=0;i<n;i++){
            mini=min(mini,v[i]);
            maxi=max(maxi,v[i]);
        }
        int l=mini,h=maxi,mid;
        while(l<=h){
            mid=l+(h-l)/2;
            if(possible(v,mid,m,k)){
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
    
};
