class Solution {
public:
    const int mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<long long> freq(26,0);
        for(char i:s){
            freq[i-'a']++;
        }

        while(t--){
            vector<long long> temp(26,0);
            for(int i=0;i<25;i++){
                temp[i+1]=(temp[i+1]+freq[i])%mod;
            }
            temp[0]=(temp[0]+freq[25])%mod;
            temp[1]=(temp[1]+freq[25])%mod;
            freq=temp;

        }
        int ans=0;
        for(int i:freq){
            ans=(ans+i)%mod;
        }
        return ans;
        
    }
};
