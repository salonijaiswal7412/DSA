//BFS
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> dis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else vis[i][j]=0;
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int step=q.front().second;
            q.pop();

            dis[row][col]=step;
            for(int i=0;i<4;i++){
                int r=row+dr[i];
                int c=col+dc[i];
                if(r>=0 && r<m && c>=0 && c<n && vis[r][c]==0){
                    q.push({{r,c},step+1});
                    vis[r][c]=1;
                }
            }
        }
        return dis;
        
    }
};
