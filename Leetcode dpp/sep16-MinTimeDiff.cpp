class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins(timePoints.size());
        for(int i=0;i<timePoints.size();i++){
            int h=stoi(timePoints[i].substr(0,2));
            int m=stoi(timePoints[i].substr(3));
            mins[i]=h*60+m;
        }
        sort(mins.begin(),mins.end());
        int ans=INT_MAX;
        for(int i=0;i<mins.size()-1;i++){
            ans=min(ans,mins[i+1]-mins[i]);
        }
        ans=min(ans,1440-mins.back()+mins.front());
        return ans;
        
    }
};