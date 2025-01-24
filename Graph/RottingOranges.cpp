//bfs
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        int cnt=0,cntFresh=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        int ans=0;
        
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            ans=max(ans,t);
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=r+dr[i];
                int ncol=c+dc[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
            }
        }
        if(cnt!=cntFresh) return -1;
        return ans;
        
    }
};
