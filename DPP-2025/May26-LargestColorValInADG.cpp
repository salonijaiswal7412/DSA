class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>> v(n);
        vector<int> ind(n,0);
        vector<vector<int>> dp(n,vector<int>(26));
        queue<int> q;
        for(auto i:edges){
            v[i[0]].push_back(i[1]);
            ind[i[1]]++;
        }
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
                dp[i][colors[i]-'a']=1;
            }
        }

        int ans=0,c=0;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            c++;
            for(int i=0;i<26;i++){
                ans=max(ans,dp[f][i]);
            }
            for(auto i:v[f]){
                for(int j=0;j<26;j++){
                    dp[i][j]=max(dp[i][j],dp[f][j]+(colors[i]-'a'==j));
                }
                if(--ind[i]==0){
                    q.push(i);
                }
            }
        }
        return c==n?ans:-1;
        
    }
};
