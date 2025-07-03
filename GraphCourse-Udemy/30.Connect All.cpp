//kruskal
#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> ranks;
int find(int i){
    if(parent[i]==i) return i;
    return parent[i]=find(parent[i]);
}
void unite(int x,int y){
    int s1=find(x);
    int s2=find(y);
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
int minCostConnectPoints(vector<vector<int>> points) {
    vector<pair<int,pair<int,int>>> v;
    int n=points.size();
    ranks.resize(n,1);
    parent.resize(n);
    for(int i=0;i<n;i++) parent[i]=i;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int wx=abs(points[i][0]-points[j][0]);
            int wy=abs(points[i][1]-points[j][1]);
            v.push_back({wx+wy,{i,j}});
        }
    }
    int ans=0;
    sort(v.begin(),v.end());
    for(auto i:v){
        int w=i.first;
        int u=i.second.first;
        int v=i.second.second;
        if(find(u)!=find(v)){
            unite(u,v);
            ans+=w;
        }
    }
    return ans;
}

//prims
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
        int n=points.size(),ans=0,c=0;
        vector<bool> vis(n,0);

        q.push({0,0});

        while(!q.empty() && c<n){
            auto [w,to]=q.top();
            q.pop();
            if(vis[to]) continue;

            ans+=w;
            vis[to]=1;
            c++;

            for(int i=0;i<n;i++){
                if(!vis[i]){
                    int nw=abs(points[i][0]-points[to][0])+abs(points[i][1]-points[to][1]);
                    q.push({nw,i});
                }
            }
        }
        return ans;
    }
};
