//dsu
class Solution {
public:
    class DSU{
        public:
        vector<int> parent;
        DSU(int n){
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }

        }

        int find(int i){
            if(parent[i]==i){
                return i;
            }
            return parent[i]=find(parent[i]);
        }

        void unite(int x,int y){
            int s1=find(x);
            int s2=find(y);
            if(s1!=s2){
                if(s1<s2){
                    parent[s2]=s1;
                }
                else{
                    parent[s1]=s2;
                }
            }
        }

    };
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU g(26);
        int n=baseStr.size(),m=s1.size();
        for(int i=0;i<m;i++){
            g.unite(s1[i]-'a',s2[i]-'a');
        }
        string ans;
        for(int i=0;i<n;i++){
            ans+='a'+g.find(baseStr[i]-'a');
        }
        return ans;

        
    }
};
