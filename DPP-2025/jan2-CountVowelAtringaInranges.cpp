class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        unordered_set<char> vowels{'a','e','i','o','u'};
        vector<int> pre(words.size());
        int s=0;
        for(int i=0;i<words.size();i++){
            string curr=words[i];
            if(vowels.count(curr[0]) && vowels.count(curr[curr.size()-1]))
            s++;
            pre[i]=s;
        }

        for(int i=0;i<queries.size();i++){
            auto curr=queries[i];
            ans[i]=pre[curr[1]]-(curr[0]==0?0:pre[curr[0]-1]);
        }
        return ans;
        
    }
};
