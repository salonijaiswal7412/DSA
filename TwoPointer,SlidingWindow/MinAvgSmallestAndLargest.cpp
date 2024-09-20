class Solution {
public:
    double minimumAverage(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<double> avg;
    int l=0,r=nums.size()-1;
    while(l<=r){
        double s=(nums[l]+nums[r])/2.0;
        avg.push_back(s);
        l++;r--;

    }
    return *min_element(avg.begin(),avg.end());
    
        
    }
};