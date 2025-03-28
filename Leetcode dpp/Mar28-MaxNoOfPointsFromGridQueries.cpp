class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m=grid.size(), n=grid[0].size();
        vector<int> ans(queries.size(),0);
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        vector<pair<int,int>> sorted;
        for(int i=0;i<queries.size();i++){
            sorted.push_back({queries[i],i});
        }
        sort(sorted.begin(),sorted.end());

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt=0;
        q.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        for(auto [x,idx]:sorted){
            while(!q.empty() && q.top().first<x){
                auto [val,pos]=q.top();
                q.pop();
                int r=pos.first,c=pos.second;
                cnt++;
                for(int i=0;i<4;i++){
                    int nr=r+dr[i],nc=c+dc[i];
                    
                    if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc]){
                        q.push({grid[nr][nc],{nr,nc}});
                        vis[nr][nc]=1;
                    }
                }

            }
            ans[idx]=cnt;
        }
        return ans;
        
    }
};
