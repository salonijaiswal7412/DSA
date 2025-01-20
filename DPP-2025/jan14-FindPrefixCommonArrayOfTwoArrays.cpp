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

//as per solution
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int n=A.size();
        vector<int>freq(n+1,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(++freq[A[i]]==2)c++;
            if(++freq[B[i]]==2) c++;
            ans.push_back(c);
        }
        return ans;
        
    }
};
