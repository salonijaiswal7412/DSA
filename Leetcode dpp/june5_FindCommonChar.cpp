class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>minf(26,INT_MAX);
        for(string i:words){
            vector<int> freq(26,0);
            for(char j:i){
                freq[j-'a']++;
            }
            for(int i=0;i<26;i++){
                minf[i]=min(minf[i],freq[i]);
            }
        }
        vector<string> ans;
        for(int i=0;i<26;i++){
            while(minf[i]-->0){
                ans.push_back(string(1,i+'a'));
            }
        }
        return ans;
        
    }
};
