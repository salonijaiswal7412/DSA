class Solution {
public:
void comb(int i,int t,vector<int>& a,vector<int>& temp,vector<vector<int>>& ans){
    if(i==a.size()){
        if(t==0){
            ans.push_back(temp);
        }
        return;
    }
    if(a[i]<=t){
        temp.push_back(a[i]);
        comb(i,t-a[i],a,temp,ans);
        temp.pop_back();
    }
    comb(i+1,t,a,temp,ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        comb(0,target,candidates,temp,ans);
        return ans;
        
    }
};