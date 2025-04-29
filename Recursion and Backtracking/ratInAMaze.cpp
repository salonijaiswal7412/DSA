class Solution {
  public:
    void f(int i,int j,int n,string s,vector<string>&ans,vector<vector<int>>& mat,vector<vector<int>>& vis){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return ;
        }
        //down
        if(i+1<n && !vis[i+1][j] && mat[i+1][j]){
            vis[i+1][j]=1;
            f(i+1,j,n,s+"D",ans,mat,vis);
            vis[i+1][j]=0;
        }
        //left
        if(j-1>=0 && !vis[i][j-1] && mat[i][j-1]){
            vis[i][j-1]=1;
            f(i,j-1,n,s+"L",ans,mat,vis);
            vis[i][j-1]=0;
        }
        //right
        if(j+1<n && !vis[i][j+1] && mat[i][j+1]){
            vis[i][j+1]=1;
            f(i,j+1,n,s+"R",ans,mat,vis);
            vis[i][j+1]=0;
        }
        //up
        if(i-1>=0 && !vis[i-1][j] && mat[i-1][j]){
            vis[i-1][j]=1;
            f(i-1,j,n,s+"U",ans,mat,vis);
            vis[i-1][j]=0;
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        if(maze[0][0]==0) return ans;
        int n=maze.size();
        vector<vector<int>> vis(n,vector<int> (n,0));
        vis[0][0]=1;
        f(0,0,n,"",ans,maze,vis);
        return ans;
    }
};
