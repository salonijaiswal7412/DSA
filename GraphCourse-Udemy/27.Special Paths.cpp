#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> ranks;
int find(int i){
    if(parent[i]==i)return i;
    return parent[i]=find(parent[i]);
}
void unite(int x,int y){
    int s1=find(x),s2=find(y);
    if(s1!=s2){
        if(ranks[s1]<ranks[s2]){
            parent[s1]=s2;
            ranks[s2]+=ranks[s1];
        }
        else{
            parent[s2]=s1;
            ranks[s1]+=ranks[s2];
        }
    }
    
}
int specialPath(int n, vector<int> a, vector<vector<int>> edges,int start, int end)
{
    vector<tuple<int,int,int>> WtEdges;
    for(auto& i:edges){
        int u=i[0],v=i[1];
        WtEdges.push_back({abs(a[u-1]-a[v-1]),u,v});
    }
    sort(WtEdges.begin(),WtEdges.end());
    parent.resize(n+1);
    for(int i=0;i<n;i++) parent[i]=i;
    ranks.resize(n+1,1);
    for(auto [w,u,v]:WtEdges){
        unite(u,v);
        if(find(start)==find(end))
        return w;
    }
    return -1;
}
