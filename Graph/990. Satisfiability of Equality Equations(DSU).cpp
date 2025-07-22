class Solution {
public:
    class Dsu {
        public:
        vector<int> parent;
        vector<int> ranks;
        Dsu(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
            ranks.resize(n, 1);
        }

        int find(int i) {
            if (i == parent[i])
                return i;
            return parent[i] = find(parent[i]);
        }

        bool unite(int x, int y) {
            int s1 = find(x), s2 = find(y);
            if (s1 == s2)
                return false;
            if (ranks[s1] < ranks[s2]) {
                parent[s1] = s2;
                ranks[s2] += ranks[s1];
            } else {
                parent[s2] = s1;
                ranks[s1] += ranks[s2];
            }
            return true;
        }
    };
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        Dsu d(26);
        for(auto i:equations){
            int x=i[0]-'a';
            int y=i[3]-'a';
            if(i[1]=='='){
                d.unite(x,y);
            }
        }

        for(auto i:equations){
            int x=i[0]-'a';
            int y=i[3]-'a';
            if(i[1]=='!'){
                if(d.find(x)==d.find(y)){
                    return false;
                }
            }

        }
        return true;
    }
};
