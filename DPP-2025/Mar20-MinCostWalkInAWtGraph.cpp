class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(parent[i]==-1) return i;
        return parent[i]=find(parent[i]);
    }
    void unite(int x,int y){
        int s1=find(x),s2=find(y);
        if(s1==s2) return;
        if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=rank[s1];
        }
        else{
                parent[s2]=s1;
                rank[s1]+=rank[s2];
        }
        
        
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
       parent.resize(n,-1);
       rank.resize(n,0);
       vector<unsigned int> cost(n,-1);
       for(auto& i: edges){
        unite(i[0],i[1]);
       }
       for(auto& i:edges){
        cost[find(i[0])]&=i[2];
       }
       vector<int> ans;
       for(auto& i:query){
        int s1=find(i[0]),s2=find(i[1]);
        if(s1!=s2){
            ans.push_back(-1);
        }
        else{
            ans.push_back(cost[s1]);
        }
       }
       return ans;

    }
};
