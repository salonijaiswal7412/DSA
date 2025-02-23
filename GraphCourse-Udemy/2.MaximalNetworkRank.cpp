#include<bits/stdc++.h>
using namespace std;

int maximalNetworkRank(int n, vector<vector<int>> roads) {
    int ans=0;
    vector<int> deg(n);
    vector<vector<int>> edges(n,vector<int> (n));
    for(int i=0;i<roads.size();i++){
        int a=roads[i][0];
        int b=roads[i][1];
        deg[a]++;
        deg[b]++;
        edges[a][b]++;
        edges[b][a]++;
        
        
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans=max(deg[i]+deg[j]-edges[i][j],ans);
        }
    }
    return ans;

}
