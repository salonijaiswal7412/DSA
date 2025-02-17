class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> ans;
        vector<bool> used(tiles.length(),false);

        gen(tiles,"",used,ans);
        return ans.size()-1;
        
    }
    void gen(string & tiles,string curr,vector<bool>& used,unordered_set<string>& ans){
        ans.insert(curr);
        for(int i=0;i<tiles.length();i++){
            if(!used[i]){
                used[i]=true;
                gen(tiles,curr+tiles[i],used,ans);
                used[i]=false;
            }
        }
    }
};
