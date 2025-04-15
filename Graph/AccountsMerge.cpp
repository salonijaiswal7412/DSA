//using dsu
class Solution {
public:
    class DSU{
        vector<int> parent,size;
        public:
        DSU(int n){
            parent.resize(n);
            for(int i=0;i<n;i++)
                parent[i]=i;
            size.resize(n,1);
        }
        int find(int i){
            if(i==parent[i])
                return i;
            return parent[i]=find(parent[i]);
        }
        void unite(int x,int y){
            int s1=find(x),s2=find(y);
            if(s1==s2) return;
            if(size[s1]<size[s2]){
                parent[s1]=s2;
                size[s2]+=size[s1];
            }
            else{
                parent[s2]=s1;
                size[s1]+=size[s2];
            }
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int> m;
        DSU s(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j])==m.end()){
                    m[accounts[i][j]]=i;
                }
                else{
                    s.unite(i,m[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> mail(n);
        for(auto& i: m){
            auto mails=i.first;
            int idx=s.find(i.second);
            mail[idx].push_back(mails);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mail[i].size()==0) continue;
            sort(mail[i].begin(),mail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto j:mail[i]){
                temp.push_back(j);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};
