

class Solution {
public:
    int firstBadVersion(int n) {
        int l=0,h=n-1;
        int m=l+(h-l)/2;
        while(l<=h){
            
            if(isBadVersion(m)) h=m-1;
            else l=m+1;
            m=l+(h-l)/2;
        }
        return m;
        
    }
};
