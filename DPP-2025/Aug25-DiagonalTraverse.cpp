class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int k=m+n-1;
        vector<vector<int>> ans(k);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> res;
        bool flag=false;
        for(auto& i:ans){
            if(!flag){
                reverse(i.begin(),i.end());
            }
            for(auto j:i){
                res.push_back(j);
            }
            flag=!flag;
        }
        return res;
        
    }
};
