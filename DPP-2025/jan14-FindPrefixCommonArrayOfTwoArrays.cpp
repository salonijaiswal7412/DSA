//my approach
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<char,int> m;
        vector<int> ans(A.size());
        for(int i=0;i<A.size();i++){
            m[A[i]]++;
            m[B[i]]++;
            for(auto [ch,freq]:m){
                ans[i]+=(freq/2);
            }
        }
        return ans;
        
    }
};
