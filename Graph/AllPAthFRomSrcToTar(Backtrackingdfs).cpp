class Solution {
    public:
        void dfs(int n,vector<int>& v,vector<vector<int>>& graph,vector<vector<int>>& ans){
            v.push_back(n);
            if(n==graph.size()-1){
                ans.push_back(v);
            }
            for(auto i:graph[n]){
                dfs(i,v,graph,ans);
            }
            v.pop_back();
        }
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            vector<vector<int>> ans;
            vector<int>v;
            dfs(0,v,graph,ans);
            return ans;
            
        }
    }; 
