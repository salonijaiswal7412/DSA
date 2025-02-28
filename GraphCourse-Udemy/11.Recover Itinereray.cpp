class Solution {
public:
    void dfs(string s,vector<string>& ans,unordered_map<string,vector<string>>& m){
        vector<string>& dest=m[s];
        while(!dest.empty()){
            string next=dest.back();
            dest.pop_back();
            dfs(next,ans,m);
        }
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> m;
        for(auto& i:tickets){
            m[i[0]].push_back(i[1]);
        }
        for(auto& [_, dest]:m){
            sort(dest.rbegin(),dest.rend());
        }
        vector<string> ans;
        dfs("JFK",ans,m);
        reverse(ans.begin(),ans.end());
        return ans;

        
        
    }
};
