#include<bits/stdc++.h>
using namespace std;
bool dfs(int n,vector<bool>& vis,vector<bool>&path,vector<vector<int>>& v){
    vis[n]=true;
    path[n]=true;
    for(auto i:v[n]){
        if(!vis[i]){
            if(dfs(i,vis,path,v))
            return true;
        }
        else if(path[i]==true) return true; 
    }
    path[n]=false;
    return false;
}
bool solve(int n, vector<vector<int>>edges) {
    vector<vector<int>>v(n+1);
    for(auto & i:edges){
        v[i[0]].push_back(i[1]);
    }
    vector<bool> vis(n+1,0);
    vector<bool> path(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,vis,path,v))return true;
        }
    }
    return false;
}
