class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int max=0,c=0;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]<arr[i+1]) max=arr[i+1];
            else{
                c=i;
                break;
            }
        }
        if(max==0) return false;
        for(int i=c;i<arr.size()-1;i++){
            if(arr[i]<=arr[i+1]) return false;
        }
        return true;
        
    }
};