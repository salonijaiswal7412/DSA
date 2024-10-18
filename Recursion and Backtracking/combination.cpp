class Solution {
public:
    void backtrack(int n,int k,int idx,vector<int>& comb,vector<vector<int>>& ans){
        if(comb.size()==k){
            ans.push_back(comb);
            return ;
        }
        for(int i=idx;i<=n;i++){
            comb.push_back(i);
            backtrack(n,k,i+1,comb,ans);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        vector<vector<int>> ans;
        backtrack(n,k,1,comb,ans);
        return ans;
        
    }
};