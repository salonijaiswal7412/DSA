#include<bits/stdc++.h>
using namespace std;
int n=100005;
int* parent=new int[n];
void initialize(){
fill(parent,parent+n,-1);
}
int find(int i){
    if(parent[i]==-1)
    return i;
    return find(parent[i]);
    
    
}
int unite(int x,int y){
    int s1=find(x);
    int s2=find(y);
    
    if(s1!=s2){
        parent[s1]=s2;
    }
    
}

bool solve(vector<vector<int>> edges) {
    initialize();
    for(auto& i:edges){
        if(find(i[0])==find(i[1]))
        return false;
        unite(i[0],i[1]);
    }
    
    return true;
}
