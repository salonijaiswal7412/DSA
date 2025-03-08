//using dsu for both alice and bob;
#include<bits/stdc++.h>
using namespace std;
class DSU{
    public:
    vector<int>parent,ranks;int c;
    DSU(int n){
        c=n;
        parent.resize(n+1);
        ranks.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int find(int i){
        if(parent[i]==i) return i;
        return parent[i]=find(parent[i]);
    }
    bool unite(int x,int y){
        int s1=find(x),s2=find(y);
                if(s1==s2) return false;
                if(ranks[s1]<ranks[s2]){
                    parent[s1]=s2;
                    ranks[s2]+=ranks[s1];
                    c--;
                }
                else{
                    parent[s2]=s1;
                    ranks[s1]+=ranks[s2];
                    c--;
                }
                return true;
    }
    bool isConnected(){
        return c==1;
    }
};
int maxNumEdgesToRemove(int n, vector<vector<int>> edges) {
    DSU alice(n),bob(n);
    int req=0;
    for(auto & i:edges){
        if(i[0]==3){
            if(alice.unite(i[1],i[2])| bob.unite(i[1],i[2])){
                req++;
            }
        }
    }
    for(auto & i:edges){
        if(i[0]==1){
            if(alice.unite(i[1],i[2])){
                req++;
            }
            
        }
        else if(i[0]==2){
            if(bob.unite(i[1],i[2])){
                req++;
            }
        }
    }
    if(alice.isConnected() && bob.isConnected()){
        return edges.size()-req;
    }
    return -1;
}
