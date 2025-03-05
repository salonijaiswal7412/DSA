class Solution {
public:
    long long coloredCells(int n) {
        if(n==1) return 1;
        long long ans=((long long)n*n);
        ans+=(long long)(n-1)*(n-1);
        return ans;
        
    }
};
