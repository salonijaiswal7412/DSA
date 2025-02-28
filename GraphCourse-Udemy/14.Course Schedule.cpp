#include<bits/stdc++.h>
using namespace std;
bool dfs(int n,vector<int>& vis,vector<int>& path,vector<vector<int>>& v){
        vis[n]=1;
        path[n]=1;
        for(auto i:v[n]){
            if(!vis[i]){
                if(dfs(i,vis,path,v)) return true;
            }
            else if(path[i]) return true;
        }
        path[n]=0;
        return false;
    }

bool canFinish(vector<vector<int>> pre,int n) {
         vector<vector<int>> v(n);
        for(auto i:pre){
            v[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        vector<int> path(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,path,v)) return false;
            }
        }
        return true;

}
