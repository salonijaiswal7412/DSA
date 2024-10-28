class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int,int> m;
        sort(nums.begin(),nums.end());
        int ans=-1;
        for(auto i: nums){
            int root=sqrt(i);
            if(root*root==i && m.find(root)!=m.end()){
                m[i]=m[root]+1;
                ans=max(ans,m[i]);
            }
            else{
                m[i]=1;
            }
        }
        return ans;
        
    }
};
