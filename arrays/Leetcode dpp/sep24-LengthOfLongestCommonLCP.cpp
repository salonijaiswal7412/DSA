class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int> m;
        for(int i:arr1){
            string s=to_string(i);
            string pre="";
            for(char c:s){
                pre+=c;
                m[pre]++;
            }
        }
        int ans=0;
        for(int i:arr2){
            string s=to_string(i);
            string pre="";
            for(char c:s){
                pre+=c;
                if(m.find(pre)!=m.end()){
                    ans=max(ans,static_cast<int>(pre.length()));
                }
            }
        }
        return ans;
        
    }
};