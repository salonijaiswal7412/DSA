class Solution {
public:
    void dfs(int n,vector<vector<int>>& v,vector<int>& vis,long long & ans){
        vis[n]=1;
        ans++;
        for(auto i:v[n]){
            if(!vis[i]){
                dfs(i,v,vis,ans);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans=((1LL)*(n)*(n-1))/2;
        vector<vector<int>> v(n);
        for(auto& i:edges){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);

        }
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long s=0;
                dfs(i,v,vis,s);
                ans-=(1LL*s*(s-1)/2);
                

            }
        }
        
        return ans;
        
    }
};
