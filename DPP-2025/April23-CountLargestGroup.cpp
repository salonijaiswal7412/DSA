class Solution {
public:
    int digit(int n){
        int s=0;
        while(n){
            s+=n%10;
            n/=10;
        }
        return s;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> m;
        int maxval=0;
        for(int i=1;i<=n;i++){
            m[digit(i)]++;
            maxval=max(maxval,m[digit(i)]);
        }
        int ans=0;
        for(auto& [i,j]:m){
            if(j==maxval){
                ans++;
            }

        }
        return ans;
    }
};
