//using dijkstra
#include<bits/stdc++.h>
using namespace std;

int shortest_path(vector<vector<int> > grid){
    //return the shortest path len
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>> dis(m,vector<int>(n,1e9));
    
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
    q.push({grid[0][0],{0,0}});
    dis[0][0]=grid[0][0];
    
    int dr[]={0,1,0,-1};
    int dc[]={1,0,-1,0};
    
    while(!q.empty()){
        auto f=q.top();
        q.pop();
        int w=f.first;
        int r=f.second.first;
        int c=f.second.second;
        if(r==m-1 && c==n-1){
            return w;
        }
        for(int i=0;i<4;i++){
            int nr=dr[i]+r;
            int nc=dc[i]+c;
            
            if(nr>=0 && nr<m && nc>=0 && nc<n){
                int cost=w+grid[nr][nc];
                if(cost<dis[nr][nc]){
                    dis[nr][nc]=cost;
                    q.push({cost,{nr,nc}});
                }
            }
        }
    }
    return dis[m-1][n-1];
    
    
}
