class Solution {
public:
    int count(int p,int n){
        long long curr=p,next=p+1;
        int tot=0;
        while(curr<=n){
            tot+=static_cast<int>(min(n+1LL,next)-curr);
            curr*=10;
            next*=10;
        }
        return tot;
    }
    int findKthNumber(int n, int k) {
        int ans=1;
        k--;
        while(k){
            int c=count(ans,n);
            if(k>=c){
                ++ans;
                k-=c;
            }
            else {
                ans*=10;
                k--;
            }
        }
        return ans;
        
    }
};