sep13-XORqueriesOfASubarray.cpp

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
      vector<int> ans;
      unordered_map<int ,int> m;
      m[0]=arr[0];
      for(int i=1;i<arr.size();i++){
        int t=arr[i]^m[i-1];
        m[i]=t;
      }
      for(auto i:queries){
        int l=i[0];
        int r=i[1];
        if(l==0 ) ans.push_back(m[r]);
        else ans.push_back(m[r]^m[l-1]);
      }
      return ans;

    }
};