class Solution {
public:
    class DSU {

    public:
        vector<int> parent, size;
        DSU(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
            size.resize(n, 1);
        }
        int find(int i) {
            if (i == parent[i]) {
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
    bool check(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU s(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int idx = 0; idx < 4; idx++) {
                    int r = dr[idx] + i;
                    int c = dc[idx] + j;
                    if (check(r, c, n) && grid[r][c] == 1) {
                        int node = i * n + j;
                        int nbr = r * n + c;
                        s.unite(node, nbr);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    continue;
                }
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> comp;
                for (int idx = 0; idx < 4; idx++) {
                    int r = dr[idx] + i;
                    int c = dc[idx] + j;
                    if (check(r, c, n)) {
                        if (grid[r][c] == 1) {
                            comp.insert(s.find(n * r + c));
                        }
                    }
                }
                int tot = 0;
                for (auto it : comp) {
                    tot += s.size[it];
                }
                ans = max(ans, tot + 1);
            }
        }
        for (int i = 0; i < n * n; i++) {
            ans = max(ans, s.size[s.find(i)]);
        }
        return ans;
    }
};
