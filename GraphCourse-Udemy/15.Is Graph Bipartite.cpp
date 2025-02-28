#include<bits/stdc++.h>
using namespace std;

bool dfs(int n,int col,vector<int>& color,vector<vector<int>>& graph){
    color[n]=col;
    for(auto i: graph[n]){
        if(color[i]==-1){
            if(!dfs(i,!col,color,graph)) return false;
        }
        else if(color[i]==col) return false;
        
    }
    return true;
}

bool isBipartite(vector<vector<int>> graph){
    int v=graph.size();
    vector<int> color(v,-1);
    for(int i=0;i<v;i++){
        if(color[i]==-1){
            if(!dfs(i,0,color,graph))return false;
        }
    }
    return true;
    
}
