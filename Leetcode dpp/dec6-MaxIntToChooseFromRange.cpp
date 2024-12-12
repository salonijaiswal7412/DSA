class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> s(banned.begin(),banned.end());
        int sum=0,ans=0;
        for(int i=1;i<=n;i++){
            if(s.find(i)==s.end()){
                sum+=i;
                if(sum<=maxSum) ans++;
                else return ans;
            }
        }
        return ans;
    }
};
