class Solution {
public:
    void comb(int idx,int target,int n,vector<int>& temp,vector<vector<int>>& ans){
        if(temp.size()==n){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        for(int i=idx;i<=9;i++){
            temp.push_back(i);
            comb(i+1,target-i,n,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int n, int target) {
        vector<int>temp;
        vector<vector<int>> ans;
        comb(1,target,n,temp,ans);
        return ans;
        
    }
};