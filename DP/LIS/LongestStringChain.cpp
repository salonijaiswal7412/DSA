class Solution {
public:
    bool check(string&s1,string&s2){
        if(s1.size()!=s2.size()+1){
            return false;
        }
        int i=0,j=0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return j==s2.size();
    }
    static bool comp(string& s1,string& s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        int ans=1;
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(check(words[i],words[prev]) && dp[i]<dp[prev]+1){
                    dp[i]=dp[prev]+1;
                }
            }
            ans=max(ans,dp[i]);

        }
        return ans;
    }
};
