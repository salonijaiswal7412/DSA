#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent,size;
    public:
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        size.resize(n,1);
    }
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);
    }
    void unite(int x,int y){
        int s1=find(x),s2=find(y);
        if(s1==s2) return;
        if(size[s1]<size[s2]){
            parent[s1]=s2;
            size[s2]+=size[s1];
        }
        else{
            parent[s2]=s1;
            size[s1]+=size[s2];
        }
    }
};

long long buildRoads(vector<vector<long long>>Coordinates){
    int n=Coordinates.size();
    vector<pair<int,pair<long long,long long>>> towns;
    for(int i=0;i<Coordinates.size();i++){
        towns.push_back({i,{Coordinates[i][0],Coordinates[i][1]}});
    }
    sort(towns.begin(),towns.end(),[](auto& a,auto& b){
        return a.second.first<b.second.first;
    });
    vector<tuple<long long,int,int>> v;
    
    for(int i=0;i<n-1;i++){
        int t1=towns[i].first,t2=towns[i+1].first;
        long long x1=towns[i].second.first,x2=towns[i+1].second.first,y1=towns[i].second.second,y2=towns[i+1].second.second;
        long long cost=min(abs(x1-x2),abs(y1-y2));
        v.push_back({cost,t1,t2});
    }
    sort(towns.begin(),towns.end(),[](auto& a,auto& b){
        return a.second.second<b.second.second;
    });
    for(int i=0;i<n-1;i++){
        int t1=towns[i].first,t2=towns[i+1].first;
        long long x1=towns[i].second.first,x2=towns[i+1].second.first,y1=towns[i].second.second,y2=towns[i+1].second.second;
        long long cost=min(abs(x1-x2),abs(y1-y2));
        v.push_back({cost,t1,t2});
    }
    DSU s(n);
    long long ans=0;
    sort(v.begin(),v.end());
    for(auto& [w,x,y]:v){
        if(s.find(x)!=s.find(y)){
            ans+=w;
            s.unite(x,y);
        }
    }
    return ans;
    
}
