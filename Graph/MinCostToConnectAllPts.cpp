//kruskal
class Solution {
public:
    vector<int> parent;
    vector<int> ranks;
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int x, int y) {
        int s1 = find(x), s2 = find(y);
        if (s1 != s2) {
            if (ranks[s1] < ranks[s2]) {
                parent[s1] = s2;
                ranks[s2] += ranks[s1];
            } else {
                parent[s2] = s1;
                ranks[s1] += ranks[s2];
            }
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<int, int>>> edges;
        int n=points.size()*points[0].size();
        ranks.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
        
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                int wx = abs(points[i][0] - points[j][0]);
                int wy = abs(points[i][1] - points[j][1]);
                edges.push_back({wx + wy, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        int ans=0;
        for(auto i:edges){
            int w=i.first;
            int u=i.second.first;
            int v=i.second.second;
            if(find(u)!=find(v)){
                unite(u,v);
                ans+=w;
            }
        }
        return ans;
    }
};
