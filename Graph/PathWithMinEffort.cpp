class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int m=h.size();
        int n=h[0].size();
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        vector<vector<int>> dis(m,vector<int>(n,1e9));
        q.push({0,{0,0}});
        dis[0][0]=0;
        int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto f=q.top();
            q.pop();
            int w=f.first;
            int x=f.second.first;
            int y=f.second.second;
            if(x==m-1 && y==n-1){
                return w;
            }
            for(int i=0;i<4;i++){
                int nr=x+dir[i][0];
                int nc=y+dir[i][1];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int val=max(w,abs(h[x][y]-h[nr][nc]));
                    if(val<dis[nr][nc]){
                        dis[nr][nc]=val;
                        q.push({dis[nr][nc],{nr,nc}});
                    }
                }
            }

        }
        return -1;
        
    }
};
