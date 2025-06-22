class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        while(n%k){
            s+=fill;
            n++;
        }
        vector<string> ans;
        for(int i=0;i<n;i+=k){
            string temp="";
            for(int j=i;j<i+k;j++){
                temp+=s[j];
            }
            ans.push_back(temp);
        }
        return ans;

        
    }
};
