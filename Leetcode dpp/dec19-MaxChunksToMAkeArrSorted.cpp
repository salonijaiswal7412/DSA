class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int idxSum=0,valSum=0,ans=0;
        for(int i=0;i<arr.size();i++){
            valSum+=arr[i];
            idxSum+=i;
            if(valSum==idxSum) ans++;
        }
        return ans;
        
    }
};
