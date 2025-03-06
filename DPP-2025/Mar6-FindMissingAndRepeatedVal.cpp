
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size()*grid[0].size();
        unordered_map<int,int>m(n);
        for(auto i:grid){
            for(auto j:i){
                m[j]++;
            }
        }
        int x=-1,y=-1;
        for(int i=1;i<=n;i++){
            if(!m.count(i))
            y=i;
            else if(m[i]==2)
            x=i;
        }
        return {x,y};
        
    }
};
