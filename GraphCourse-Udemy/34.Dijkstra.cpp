//to print path of dijkstra
#include<bits/stdc++.h>
using namespace std;
class Dijkstra{
    public:
    vector<int>dis,parent;
    vector<vector<pair<int,int>>>v;
    Dijkstra(int n,vector<vector<pair<int,int>>> a){
        parent.resize(n+1,0);
        dis.resize(n+1,1e9);
        v=a;
    }
    void find_dis(int root){
        set<pair<int,int>>s;
        s.insert({0,root});
        dis[root]=0;
        parent[root]=root;
        while(!s.empty()){
            pair<int,int>p=*s.begin();
            int w=p.first;
            int node=p.second;
            s.erase(p);
            for(auto& i:v[node]){
                int cw=i.first;
                int nbr=i.second;
                if(cw+w<dis[nbr]){
                    s.erase({dis[nbr],nbr});
                    dis[nbr]=cw+w;
                    parent[nbr]=node;
                    s.insert({dis[nbr],nbr});
                }
            }
        }
    }
    vector<int>find_path(int root){
        vector<int>path;
        int p=root;
        while(p!=1){
            path.push_back(p);
            p=parent[p];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};

vector<int> shortestPath(vector<vector<int>> roads,int n)
{
    vector<vector<pair<int,int>>>v(n+1);
    for(auto i:roads){
        v[i[0]].push_back({i[2],i[1]});
        v[i[1]].push_back({i[2],i[0]});
    }
    Dijkstra d(n,v);
    d.find_dis(1);
    return d.find_path(n);
}
