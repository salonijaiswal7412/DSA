class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> p;
        int maxV=0,ans=0;
        for(auto& i:events){
            int l=i[0],h=i[1],val=i[2];
            while(!p.empty() && p.top().first<l){
                maxV=max(maxV,p.top().second);
                p.pop();

            }
            ans=max(ans,maxV+val);
            p.push({h,val});

        }
        return ans;
        
    }
};
