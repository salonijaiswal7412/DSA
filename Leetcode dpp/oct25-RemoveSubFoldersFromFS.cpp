class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(),folder.end());
        unordered_map<string,int> m;
        for(auto s:folder){
            string tmp="";
            bool f=0;
            int n=s.size();
            for(int i=0;i<n;i++){
                tmp.push_back(s[i]);
                if(i==n-1 && m[tmp]){
                    f=1;
                    break;
                }
                else if(m[tmp] && s[i+1]=='/'){
                    f=1;
                    break;
                }
            }
            if(!f) {m[tmp]++; ans.push_back(tmp);}
        }
        return ans;
        
    }
};
