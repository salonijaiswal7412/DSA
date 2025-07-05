class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i:arr){
            m[i]++;
        }
        int ans=0;
        for(auto& [i,j]:m){
            if(i==j) ans=max(ans,i);
        }
        return ans==0?-1:ans;
        
    }
};
