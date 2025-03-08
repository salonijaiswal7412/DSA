class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.length();
        int ans=1e9;
        for(int i=0;i<=n-k;i++){
            string temp=blocks.substr(i,k);
            int c=0;
            for(auto j:temp){
                if(j=='W') c++;
            }
            ans=min(c,ans);
        }
        return ans;
        
    }
};
