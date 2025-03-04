#include<bits/stdc++.h>
using namespace std;
vector<int> parent(1000005,-1);
int find(int i){
    if(parent[i]==-1)return i;
    return find(parent[i]);
}
void unite(int x,int y){
    if(find(x)!=find(y)){
        parent[find(x)]=find(y);
    }
}


vector<int> findUselessConnection(vector<vector<int>> edges) {
    
    vector<vector<int>> ans;
    for(auto& i:edges){
        if(find(i[0])==find(i[1])){
            ans.push_back({i[0],i[1]});
        }
        unite(i[0],i[1]);
    }
    return ans[ans.size()-1];
    
        
}
