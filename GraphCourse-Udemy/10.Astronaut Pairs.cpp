#include<bits/stdc++.h>
using namespace std;
void dfs(int n,vector<int>& vis,vector<vector<int>>& v,int& size){
    vis[n]=1;
    size++;
    for(auto i:v[n]){
        if(!vis[i]){
            dfs(i,vis,v,size);
        }
    }
}
int count_pairs(int N, vector<pair<int,int> > astronauts){
    vector<vector<int>> v(N);
    for(auto& i:astronauts){
        v[i.first].push_back(i.second);
        v[i.second].push_back(i.first);
    }
    vector<int> vis(N,0);
    vector<int> c;
    for(int i=0;i<N;i++){
        if(!vis[i]){
            int size=0;
            dfs(i,vis,v,size);
            c.push_back(size);
            
        }
    }
    long long int ans=(N)*(N-1)/2;
    for(auto i:c){
        ans-=(i)*(i-1)/2;
    }
    return ans;
    
}
