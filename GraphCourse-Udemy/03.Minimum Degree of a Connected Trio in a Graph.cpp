#include<bits/stdc++.h>
using namespace std;

int minTrioDegree(int n, vector<vector<int>> edges) {
    vector<int> deg(n+1,0);
    vector<vector<int>> v(n+1,vector<int>(n+1,0));
    for(int i=0;i<edges.size();i++){
        int a=edges[i][0];
        int b=edges[i][1];
        deg[a]++;
        deg[b]++;
        v[a][b]++;
        v[b][a]++;
    }
    int ans=INT_MAX;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(v[i][j] && v[j][k] && v[k][i]){
                    ans=min(ans,deg[i]+deg[j]+deg[k]-6);
                }
            }
        }
    }
    return ans==INT_MAX?-1 :ans;
 
}
