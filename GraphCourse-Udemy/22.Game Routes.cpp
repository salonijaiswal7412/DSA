#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int gameRoutes(int n, vector<vector<int>> edges)
{
    vector<vector<int>> v(n+1);
    vector<int>ind(n+1,0);
    vector<int>ways(n+1,0);
    queue<int> q;
    for(auto& i:edges){
        v[i[0]].push_back(i[1]);
        ind[i[1]]++;
    }
    for(int i=1;i<=n;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }
    ways[1]=1;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(auto i:v[f]){
            ways[i]=(ways[i]+ways[f])%mod;
            if(--ind[i]==0){
                q.push(i);
            }
        }
    }
    return ways[n];
}
