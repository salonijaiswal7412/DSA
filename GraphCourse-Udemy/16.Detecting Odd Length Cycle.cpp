//using concept of bipartite graph
#include<bits/stdc++.h>
using namespace std;

bool dfs(int n,int col,vector<int>& color,vector<vector<int>>& graph){
    color[n]=col;
    for(auto i:graph[n]){
        if(color[i]==-1){
            if(!dfs(i,!col,color,graph)) return false;
        }
        else if(color[i]==col) return false;
    }
    return true;
}

bool solve(vector<vector<int>> graph)

{
    int n=graph.size();
    vector<int> color(n,-1);
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(!dfs(i,0,color,graph)) return true;
        }
    }
    return false;
    
}
