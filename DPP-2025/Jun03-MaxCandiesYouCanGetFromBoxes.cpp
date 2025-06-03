class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        queue<int> q;
        vector<int> vis(n,0),box(n,0);

        for(int i:initialBoxes){
            box[i]=1;
            if(status[i]==1){
                q.push(i);
                vis[i]=1;
            }
        }
        int ans=0;
        while(!q.empty()){
            int f=q.front();
            q.pop();

            ans+=candies[f];

            for(int i:keys[f]){
                if(status[i]==0){
                    status[i]=1;
                    if(box[i] && !vis[i]){
                        q.push(i);
                        vis[i]=1;
                    }
                }
            }

            for(int i:containedBoxes[f]){
                box[i]=1;
                if(!vis[i] && status[i]){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        return ans;
    }
};
