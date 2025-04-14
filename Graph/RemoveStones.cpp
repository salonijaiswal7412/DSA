//dfs
class Solution {
public:
    void dfs(vector<vector<int>>&v,vector<bool>& vis,int i){
        vis[i]=1;
        for(auto j:v[i]){
            if(!vis[j]){
                dfs(v,vis,j);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        int c=0;
        vector<bool> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(v,vis,i);
                c++;
            }
        }
        return n-c;
        
    }
};
//dsu
class Solution {
public:
    class DSU {
    public:
        vector<int> parent, size;
        int c;
        DSU(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
            size.resize(n, 1);
            c=n;
        }
        int find(int i) {
            if (i == parent[i])
                return i;
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
            c--;
        }
    };

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU s(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0]|| stones[i][1]==stones[j][1]){
                    s.unite(i,j);
                }
            }
        }
        return n-s.c;
    }
};
