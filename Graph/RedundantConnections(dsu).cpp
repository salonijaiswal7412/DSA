class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    void initialise(){
        parent.resize(1001);
        for (int i = 0; i < 1001; i++) parent[i] = i;
        rank.resize(1001,1);
    }
    int find_set(int i){
        if(parent[i]==i)return i;
        return parent[i]=find_set(parent[i]);
    }
    void unite(int x,int y){
        int s1=find_set(x);
        int s2=find_set(y);
        if(rank[s1]<rank[s2]){
            parent[s1]=s2;
            rank[s2]+=rank[s1];
        }
        else{
            parent[s2]=s1;
            rank[s1]+=rank[s2];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        initialise();
        vector<vector<int>> ans;
        for(auto& i:edges){
            if(find_set(i[0])==find_set(i[1])){
                ans.push_back({i[0],i[1]});
            }
            unite(i[0],i[1]);
        }
        return ans[ans.size()-1];



        
    }
};
