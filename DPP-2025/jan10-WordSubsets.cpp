class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> m;
        for(auto i:words2){
            unordered_map<char,int> curr;
            for(char c: i){
                curr[c]++;
                m[c]=max(m[c],curr[c]);

            }
        }
        vector<string> ans;
        for(auto i:words1){
            unordered_map<char,int> curr;
            for(auto c: i){
                curr[c]++;
            }
            bool flag=true;
            for(auto [ch,freq]: m){
                if(curr[ch]<freq){
                    flag=false;
                    break;
                }
            }
            if(flag)
            ans.push_back(i);
        }
        return ans;
        
    }
};
