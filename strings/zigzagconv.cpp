class Solution {
public:
    string convert(string s, int nr) {
        vector<string> arr;
        for(int i=0;i<nr;i++){
            arr.push_back("");
        }
        int n=s.length();
        int i=0;
        while(i<n){
            for(int j=0;j<nr && i<n;j++){
                arr[j]+=s[i++];
            }
            for(int j=nr-2;j>0 && i<n;j--){
                 arr[j]+=s[i++];
            }
        }
        string ans="";
        for(string i:arr){
            ans+=i;
        }
        return ans;
    }
};