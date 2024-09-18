class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //learning the concept of custom sort in c++;
        sort(nums.begin(),nums.end(),[](int& a,int& b){
            return to_string(a)+to_string(b)>to_string(b)+to_string(a);
        });
        if(nums[0]==0) return "0";
        string ans;
        for(auto i:nums){
            ans+=to_string(i);
        }
        return ans;
        
    }
};