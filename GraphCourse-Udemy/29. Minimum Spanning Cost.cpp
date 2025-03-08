//KRUSKAL ALGORITHM
#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> ranks;
int find(int i){
    if(parent[i]==i) return i;
    return parent[i]=find(parent[i]);
}
void unite(int x,int y){
    int s1=find(x),s2=find(y);
    if(s1!=s2)
    {
        if(ranks[s1]<ranks[s2]){
            parent[s1]=s2;
            ranks[s2]+=ranks[s1];
        }
        else {
            parent[s2]=s1;
            ranks[s1]+=ranks[s2];
        }
    }
}

int MST(int n, vector<vector<int>> edges)
{
    parent.resize(n+1);
    for(int i=0;i<=n;i++) parent[i]=i;
    ranks.resize(n+1,1);
    sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>& b){
        return a[2]<b[2];
    });
    int ans=0,c=0;
    for(auto i:edges){
        int u=i[0],v=i[1],w=i[2];
        if(find(u)!=find(v)){
            unite(u,v);
            ans+=w;
            c++;
        }
        if(c==n-1) break;
    }
    return ans;
    
}

//PRIM ALGORITHM
#include<bits/stdc++.h>
using namespace std;

int MST(int n, vector<vector<int>> edges)
{
    vector<vector<pair<int,int>>> v(n+1);
    for(auto i:edges){
        v[i[0]].push_back({i[1],i[2]});
        v[i[1]].push_back({i[0],i[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    vector<bool> vis(n+1,0);
    q.push({0,1});
    int ans=0;
    while(!q.empty()){
        auto f=q.top();
        q.pop();
        int w=f.first;
        int to=f.second;
        if(vis[to]) continue;
        ans+=w;
        vis[to]=1;
        for(auto i:v[to]){
            if(!vis[i.first]){
                q.push({i.second,i.first});
            }
        }
    }
    return ans;
    
}
