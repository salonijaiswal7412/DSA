#include<bits/stdc++.h>
using namespace std;
bool dfs(int p,int n,vector<int>& vis,vector<vector<int>>& v){
    vis[n]=1;
    for(auto i:v[n]){
        if(!vis[i]){
            if(dfs(n,i,vis,v))
            return true;
        }
        else if(i!=p) return true;
    }
    return false;
}
bool solve(int n, vector<vector<int> > edges) {
    vector<vector<int>>  v(n+1);
    for(auto& i:edges){
        v[i[0]].push_back(i[1]);
        v[i[1]].push_back(i[0]);
    }
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(-1,i,vis,v)) return true;
        }
    }
    return false;

    
}
