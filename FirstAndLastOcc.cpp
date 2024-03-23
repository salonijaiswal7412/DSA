class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1,mid,first=-1,last=-1;
        while(l<=h){
            mid=l+(h-l)/2;
            if(nums[mid]==target){
                first=mid;
                h=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        if(first==-1)return {-1,-1};
        l=0,h=n-1,mid=0;
        while(l<=h){
            mid=l+(h-l)/2;
            if(nums[mid]==target){
                last=mid;
                l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return {first,last};
        
    }
};
