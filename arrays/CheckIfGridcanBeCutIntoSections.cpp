class Solution {
public:
    bool check(vector<vector<int>> a){
        sort(a.begin(),a.end());
        int x=a[0][1];
        int c=0;
        for(auto i: a){
            if(x<=i[0]){
                c++;
            }
            x=max(x,i[1]);
        }
        return c>=2;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x,y;
        for(auto i:rectangles){
            x.push_back({i[0],i[2]});
            y.push_back({i[1],i[3]});
        }
        return check(x)||check(y);
        
    }
};
