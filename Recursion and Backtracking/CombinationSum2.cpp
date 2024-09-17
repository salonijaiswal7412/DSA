class Solution {
public:
    void comb(int idx,int t,vector<int>& a,vector<int>& temp,vector<vector<int>>& ans){
        if(t==0){
            ans.push_back(temp);
            return ;
        }
        for(int i=idx;i<a.size();i++){
            if(i>idx && a[i]==a[i-1])continue;
            if(a[i]>t) break;
            temp.push_back(a[i]);
            comb(i+1,t-a[i],a,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        comb(0,target,candidates,temp,ans);
        return ans;
        
    }
};