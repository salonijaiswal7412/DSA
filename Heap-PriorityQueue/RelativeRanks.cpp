class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> p;
        vector<string> ans(score.size());
        for(int i=0;i<score.size();i++){
            p.push({score[i],i});
        }
        vector<string> r={"Gold Medal","Silver Medal","Bronze Medal"};
        int num=1;
        while(!p.empty()){
            auto top=p.top();
            p.pop();
            int t=top.second;
            if(num<4){
                ans[t]=r[num-1];
            }
            else{
                ans[t]=to_string(num);
            }
            num++;
        }
        return ans;
        
    }
};