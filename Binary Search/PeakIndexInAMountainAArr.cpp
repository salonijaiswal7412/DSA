class Solution {

    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=1,h=n-2,mid;
        while(l<=h){
            mid=l+(h-l)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            return mid;
            else if(arr[mid]>arr[mid-1])
            l=mid+1;
            else h=mid-1;
        }
        return 0;
        
    }
};
