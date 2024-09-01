//print entire pascal triangle given the no of rows
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++){
            vector<int> t;
            long long a=1;
            t.push_back(a);
            for(int j=1;j<i;j++){
                a*=(i-j);
                a/=j;
                t.push_back(a);
            }
            ans.push_back(t);

        }
        return ans;
        
    }
};