class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0; 
        vector<bool> sieve(n,true);
        sieve[0]=sieve[1]=false;
        for(int i=2;i*i<n;i++){
            for(int j=i*i;j<n;j+=i){
                sieve[j]=false;
            }
            
        }
        int c=0;
        for(auto i:sieve){
            if(i==true)c++;
        }
        return c;
        
    }
};
