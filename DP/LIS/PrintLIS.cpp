class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n,1);
        vector<int> hash(n);
        int last=0,maxl=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(arr[i]>arr[prev] && dp[prev]+1>dp[i]){
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            }
            if(maxl<dp[i]){
                maxl=dp[i];
                last=i;
            }
        }
        vector<int> ans;
        ans.push_back(arr[last]);
        while(hash[last]!=last){
            last=hash[last];
            ans.push_back(arr[last]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
