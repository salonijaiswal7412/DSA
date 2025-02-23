#include<bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>>edges)
{
    int v=edges.size();
    unordered_map<int,int> m;
    for(int i=0;i<v;i++){
        m[edges[i][0]]++;
        m[edges[i][1]]++;
    }
    int ans=0;
    for(auto& pair:m){
        int i=pair.first,j=pair.second;
        if(m[i]==v){
            ans=i;
            break;
        }
    }
    return ans;
   
    
}
