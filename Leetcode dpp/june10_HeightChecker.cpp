class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> n=heights;
        sort(n.begin(),n.end());
        int c=0;
        for(int i=0;i<n.size();i++){
            if(n[i]!=heights[i])
            c++;
        }
        return c;
    }
};
