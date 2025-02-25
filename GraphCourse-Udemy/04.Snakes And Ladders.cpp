#include<bits/stdc++.h>
using namespace std;
class Graph{
    list<int> *l;
    int V;
    
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V+1];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
    }
    
    int minCostBFS(int src,int dest){
        queue<int> q;
        vector<bool> visited(V,false);
        vector<int> dist(V,0);
        
        q.push(src);
        visited[src] = true;
        dist[src] = 0;
        
        while(!q.empty()){
            int f = q.front();
            q.pop();
            
            for(int nbr : l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    dist[nbr] = dist[f] + 1;
                }
            }
        }
        return dist[dest];
    }

};

int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    vector<int> board(n+1,0);
    for(auto& i:snakes){
        int s=i.first;
        int e=i.second;
        board[s]=e-s;
        
    }
    for(auto& i:ladders){
        int s=i.first;
        int e=i.second;
        board[s]=e-s;
    }
    
    Graph g(n+1);
    for(int i=1;i<n;i++){
        for(int j=1;j<=6;j++){
            int v=i+j;
            v+=board[v];
            if(v<=n){
                g.addEdge(i,v);
            }
        }
    }
    return g.minCostBFS(1,n);
    
}
