#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> v(n);
    for(auto i:flights){
        v[i[0]].push_back({i[1],i[2]});
    }
    queue<pair<int,pair<int,int>>> q;
    vector<int> dis(n,1e9);
    q.push({0,{src,0}});
    dis[src]=0;
    while(!q.empty()){
        auto f=q.front();
        q.pop();
        int c=f.first;
        int node=f.second.first;
        int w=f.second.second;
        
        if(c>k) continue;
        for(auto i:v[node]){
            int nbr=i.first;
            int wt=i.second;
            if(wt+w<dis[nbr]){
                dis[nbr]=w+wt;
                q.push({c+1,{nbr,wt+w}});
            }
        }
    }
    return dis[dst]==1e9?-1:dis[dst];
    
}
