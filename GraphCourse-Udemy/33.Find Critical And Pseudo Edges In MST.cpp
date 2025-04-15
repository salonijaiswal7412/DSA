#include<bits/stdc++.h>
using namespace std;
class DSU {
        vector<int> parent, size;

    public:
        DSU(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
            size.resize(n, 1);
        }
        int find(int i) {
            if (parent[i] == i) {
                return i;
            }
            return parent[i] = find(parent[i]);
        }
        void unite(int x, int y) {
            int s1 = find(x), s2 = find(y);
            if (s1 == s2)
                return;
            if (size[s1] < size[s2]) {
                parent[s1] = s2;
                size[s2] += size[s1];
            } else {
                parent[s2] = s1;
                size[s1] += size[s2];
            }
        }
};
int mst(int n,vector<vector<int>>& v,int exc=-1,int inc=-1){
    int ans=0;
    int c=0;
    DSU s(n);
    if(inc!=-1){
        int x=v[inc][0];
        int y=v[inc][1];
        int w=v[inc][2];
        if(s.find(x)!=s.find(y)){
            c++;
            ans+=w;
            s.unite(x,y);
        }
    }
    for(int i=0;i<v.size();i++){
        if(i==inc||i==exc) continue;
        int x=v[i][0];
        int y=v[i][1];
        int w=v[i][2];
        if(s.find(x)!=s.find(y)){
            c++;
            ans+=w;
            s.unite(x,y);
        }
        
    }
    return (n-1==c)?ans:INT_MAX;
}
vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> edges){
    vector<vector<int>> v(edges.size());
    for(int i=0;i<v.size();i++){
        v[i]=edges[i];
        v[i].push_back(i);
    }
    sort(v.begin(),v.end(),[](auto& a,auto& b){
        return a[2]<b[2];
    });
    vector<int> critical,pseudo;
    int ideal=mst(n,v);
    for(int i=0;i<v.size();i++){
        if(ideal<mst(n,v,i)){
            critical.push_back(v[i][3]);
        }
        else if(ideal==mst(n,v,-1,i)){
            pseudo.push_back(v[i][3]);
        }
    }
    sort(critical.begin(),critical.end());
    sort(pseudo.begin(),pseudo.end());
    return {critical,pseudo};
    
}
