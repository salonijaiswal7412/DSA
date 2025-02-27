class Solution {
public:
    void helper(int node,vector<int>& vis,vector<vector<int>> rooms){
        vis[node]=1;
        for(auto i:rooms[node]){
            if(!vis[i]){
                helper(i,vis,rooms);
                
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        helper(0,vis,rooms);
        for(int i=0;i<vis.size();i++){
            if(!vis[i]) return false;
        }
        return true;

        
    }
};
