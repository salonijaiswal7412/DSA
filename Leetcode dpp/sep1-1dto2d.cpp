class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& a, int m, int n) {
        vector<vector<int>>ans;
        int x=0;
        if(m*n!=a.size())return ans;
        for(int i=1;i<=m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(a[x++]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
//O(m*n)