class Solution {
public:
    void solve(int i,string digits,string map[],string& output,vector<string>& ans){
        if(i>=digits.length()){
            ans.push_back(output);
            return;
        }
        int n=digits[i]-'0';
        string val=map[n];
        for(int j=0;j<val.length();j++){
            output.push_back(val[j]);
            solve(i+1,digits,map,output,ans);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) return ans;
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output;
        solve(0,digits,map,output,ans);
        return ans;
        
    }
};