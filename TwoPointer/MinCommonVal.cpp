class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        int a=0,b=0;
        while(a<nums1.size() && b<nums2.size()){
            if(nums1[a]==nums2[b]) {return nums1[a];
            a++;
            b++;}
            else if(nums1[a]<nums2[b]) a++;
            else b++;
        }
        return -1;
    }
};
