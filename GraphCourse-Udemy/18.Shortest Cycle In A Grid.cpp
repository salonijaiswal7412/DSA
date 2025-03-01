#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<vector<int>> edges){
    vector<vector<int>>v(n);
    for(auto& i:edges){
        v[i[0]].push_back(i[1]);
        v[i[1]].push_back(i[0]);
        
    }
    int ans=1e9;
    for(int i=0;i<n;i++){
        vector<int> dis(n,1e9);
        vector<int> parent(n,-1);
        queue<int> q;
        q.push(i);
        dis[i]=0;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(auto nbr:v[f]){
                if(dis[nbr]==1e9){
                    dis[nbr]=dis[f]+1;
                    parent[nbr]=f;
                    q.push(nbr);
                }
                else if(parent[f]!=nbr && parent[nbr]!=f){
                    ans=min(ans,dis[f]+dis[nbr]+1);
                }
            }
        }
    }
    return ans==1e9?-1:ans;
    
}
