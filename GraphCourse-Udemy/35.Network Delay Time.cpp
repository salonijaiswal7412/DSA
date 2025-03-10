//dijkstra
#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> times, int n, int k) {
    vector<vector<pair<int,int>>> v(n+1);
    vector<int> dis(n+1,1e9);
    for(auto i:times){
        v[i[0]].push_back({i[2],i[1]});
    }
    set<pair<int,int>> s;
    s.insert({0,k});
    dis[k]=0;
    while(!s.empty()){
        pair<int,int> p=*s.begin();
        int w=p.first;
        int node=p.second;
        s.erase(p);
        for(auto i:v[node]){
            int cw=i.first;
            int nbr=i.second;
            if(cw+w<dis[nbr]){
                s.erase({dis[nbr],nbr});
                dis[nbr]=cw+w;
                s.insert({dis[nbr],nbr});
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(dis[i]==1e9) return -1;
        ans=max(ans,dis[i]);
    }
    return ans;
    
    
        
}
