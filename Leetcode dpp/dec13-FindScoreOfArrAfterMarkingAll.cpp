class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        long long ans=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int n=curr.first;
            int i=curr.second;
            if(nums[i]!=-1){
                ans+=nums[i];
                if(i>0 && nums[i-1]!=-1){
                    nums[i-1]=-1;
                }
                if(i<nums.size()-1 && nums[i+1]!=-1){
                    nums[i+1]=-1;
                }
            }
        }
        return ans;
        
    }
};
