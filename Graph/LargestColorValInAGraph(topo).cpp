class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>> v(n);
        vector<vector<int>> cnt(n,vector<int>(26));
        vector<int> ind(n);
        queue<int> q;
        for(auto& i: edges){
            v[i[0]].push_back(i[1]);
            ind[i[1]]++;
        }
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
                cnt[i][colors[i]-'a']=1;
            }
        }
        vector<int> topo;
        int ans=0;
        while(!q.empty()){
            int f=q.front();
            topo.push_back(f);
            q.pop();
            for(int i=0;i<26;i++){
                ans=max(ans,cnt[f][i]);
            }
            for(auto i: v[f]){
                for(int j=0;j<26;j++){
                    cnt[i][j]=max(cnt[i][j],cnt[f][j]+(colors[i]-'a'==j));
                }
                if(--ind[i]==0){
                    q.push(i);
                }
            }

        }
        return topo.size()==n?ans:-1;
        
    }
};
