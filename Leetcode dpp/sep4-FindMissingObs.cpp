class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int s=0;
        for(auto i:rolls)
        s+=i;
        int rem=(m+n)*mean-s;
        vector<int> ans;
        if(rem<n ||rem>(n*6)) return ans;
        else{
            int full=rem/n;
            int extra=rem%n;
            for(int i=0;i<n;i++){
                if(extra>0) ans.push_back(full+1);
                else ans.push_back(full);
                extra=max(0,extra-1);
            }
        }
        return ans;
        
    }
};