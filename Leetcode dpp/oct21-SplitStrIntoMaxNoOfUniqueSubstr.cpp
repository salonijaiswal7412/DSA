class Solution {
public:
    int backtrack(int idx,string& s,unordered_set<string>& set){
        if(idx==s.size()) return 0;
        int ans=0;
        for(int i=idx+1;i<=s.size();i++){
            string sub=s.substr(idx,i-idx);
            if(set.find(sub)==set.end()){
                set.insert(sub);
                ans=max(ans,1+backtrack(i,s,set));
                set.erase(sub);
            }
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        return backtrack(0,s,set);
        
    }
};
