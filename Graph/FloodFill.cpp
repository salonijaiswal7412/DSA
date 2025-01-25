//dfs
class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& image,vector<vector<int>>& ans,int dr[],int dc[],int ini,int color){
        ans[r][c]=color;
        int m=ans.size();
        int n=ans[0].size();

        for(int i=0;i<4;i++){
            int nrow=r+dr[i];
            int ncol=c+dc[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==ini && ans[nrow][ncol]!=color){
                dfs(nrow,ncol,image,ans,dr,dc,ini,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int ini=image[sr][sc];
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        dfs(sr,sc,image,ans,dr,dc,ini,color);
        return ans;
        
    }
};
