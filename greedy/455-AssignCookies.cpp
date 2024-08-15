class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l = 0, r = 0, n = g.size(), m = s.size();
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        while (l < m && r < n) {
            if (g[r] <= s[l]) {
                r += 1;
            }
            l += 1;
        }
        return r;
    }
};
