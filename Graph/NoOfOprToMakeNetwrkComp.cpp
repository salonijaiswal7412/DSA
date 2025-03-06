//using dfs
class Solution {
public:
    void dfs(int i,int n,vector<int>& vis,vector<vector<int>>&v){
        vis[i]=1;
        for(auto j:v[i]){
            if(!vis[j]){
                dfs(j,n,vis,v);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        int ans=0;
        vector<int> vis(n,0);
        vector<vector<int>>v(n);
        for(auto& i:connections){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i]){
                ans++;
                dfs(i,n,vis,v);
            }
        }
        return ans-1;
    }
};

//using dsu
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int n){
        if(parent[n]==n) return n;
        return parent[n]=find(parent[n]);
    }
    void unite(int x,int y){
        int s1=find(x);
        int s2=find(y);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else 
            {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        rank.resize(n,0);
        int c=n;
        for(auto& i:connections){
            if(find(i[0])!=find(i[1])){
                unite(i[0],i[1]);
                c--;
            }
        }
        return c-1;
        
    }
};
