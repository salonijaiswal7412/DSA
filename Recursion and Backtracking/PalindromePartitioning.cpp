class Solution {
public:
    void helper(int idx,string s,vector<string>& subs,vector<vector<string>>& ans){
        if(idx==s.size()){
            ans.push_back(subs);
        }
        for(int i=idx;i<s.size();i++){
            if(isPalin(s,idx,i)){
                subs.push_back(s.substr(idx,i-idx+1));
                helper(i+1,s,subs,ans);
                subs.pop_back();
            }
        }
    }
    bool isPalin(string s,int l,int h){
        while(l<=h){
            if(s[l++]!=s[h--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string> subs;
        vector<vector<string>> ans;
        helper(0,s,subs,ans);
        return ans;
        
    }
};
