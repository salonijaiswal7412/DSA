#include<bits/stdc++.h>
using namespace std;

int messageRoute(int n, vector<vector<int>>edges)
{
    vector<vector<int>> v(n+1);
    for(int i=0;i<edges.size();i++){
        int x=edges[i][0];
        int y=edges[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<int> q;
    bool *vis=new bool[n+1]{0};
    int *dis=new int[n+1]{0};
    q.push(1);
    dis[1]=1;
    vis[1]=true;
    
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(auto i:v[f]){
            if(!vis[i]){
                q.push(i);
                dis[i]=dis[f]+1;
                vis[i]=true;
            }
        }
    }
    return dis[n]==(int)1e9?-1:dis[n];
    
}
