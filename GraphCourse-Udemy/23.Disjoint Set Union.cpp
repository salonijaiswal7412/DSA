#include<bits/stdc++.h>
using namespace std;
const int n=100005;
int find(int x,int parent[]){
    if(parent[x]==-1){
        return x;
    }
    return find(parent[x],parent);
}
void unite(int x,int y,int parent[]){
    int s1=find(x,parent);
    int s2=find(y,parent);
    if(s1!=s2){
        parent[s1]=s2;
    }
}
void check(int x,int y,int parent[],vector<bool>& ans){
     int s1=find(x,parent);
    int s2=find(y,parent);
    if(s1==s2) ans.push_back(1);
    else ans.push_back(0);
    
}
vector<bool> DSU(vector<vector<int>>query)
{
    
    vector<bool> ans;
    int* parent=new int[n+1];
    fill(parent,parent+n+1,-1);
    
    for(auto i:query){
        if(i[0]==1){
            unite(i[1],i[2],parent);
        }
        else {
            check(i[1],i[2],parent,ans);
        }
    }
    return ans;
    
    
}
