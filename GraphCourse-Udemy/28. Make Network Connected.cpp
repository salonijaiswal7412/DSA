#include<bits/stdc++.h>
using namespace std;
vector<int>parent;
vector<int>ranks;
int find(int i){
    if(parent[i]==i)return i;
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
        else {
            parent[s2]=s1;
            ranks[s1]+=ranks[s2];
        }
    }
    
}
int makeConnected(int n, vector<vector<int>> connections) {
    if(connections.size()<n-1) return -1;
    parent.resize(n);
    for(int i=0;i<n;i++) parent[i]=i;
    ranks.resize(n,1);
    int c=n;
    for(auto& i:connections){
        if(find(i[0])!=find(i[1])){
            c--;
            unite(i[0],i[1]);
            
        }
    }
    return c-1;

    
}
