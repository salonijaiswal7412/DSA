class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int l=0,r=0,m=players.size(),n=trainers.size();
        
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        while(l<m && r<n){
            if(players[l]<=trainers[r]){
                l++;r++;
            }
            else{
                r++;
            }
        }
        return l;
        
    }
};