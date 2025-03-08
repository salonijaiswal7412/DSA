class Solution {
public:
    vector<int> closestPrimes(int l, int r) {
        vector<bool> sieve(r+1,true);
        sieve[0]=sieve[1]=false;
        for(int i=2;i*i<=r;i++){
            if(sieve[i]){
                for(int j=i*i;j<=r;j+=i){
                    sieve[j]=false;
                }
            }
        }
        vector<int> prime;
        for(int i=l;i<=r;i++){
            if(sieve[i]){
                prime.push_back(i);
            }
        }
        vector<int> ans={-1,-1};
        int diff=1e9;
        if(prime.size()<2) return ans;
        for(int i=1;i<prime.size();i++){
            int g=prime[i]-prime[i-1];
            if(g<diff){
                diff=g;
                ans={prime[i-1],prime[i]};
            }

        }
        return ans;

        
    }
};
