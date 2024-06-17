class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int lsum=0,rsum=0;
        for(int i=0;i<=k-1;i++){
            lsum+=arr[i];
        }
        int maxs=lsum;
        int ridx=arr.size()-1;
        for(int i=k-1;i>=0;i--){
            lsum-=arr[i];
            rsum+=arr[ridx];ridx--;
            maxs=max(maxs,lsum+rsum);
        }
        return maxs;

        
    }
};
