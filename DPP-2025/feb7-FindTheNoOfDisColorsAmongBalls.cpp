class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int> ans(n);
        int j=0;
        unordered_map<int,int> cmap,bmap;
        for(auto i:queries){
            int ball=i[0];
            int color=i[1];

            if(bmap.find(ball)!=bmap.end()){
                int prev=bmap[ball];
                cmap[prev]--;

                if(cmap[prev]==0){
                    cmap.erase(prev);
                }
            }
            bmap[ball]=color;
            cmap[color]++;
            ans[j++]=cmap.size();
        }
        return ans;
        
    }
};
