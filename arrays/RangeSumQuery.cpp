class NumArray {
public:
    vector<int> a;
    NumArray(vector<int>& nums) {
        a.push_back(0);
        for(auto& i:nums){
            a.push_back(a.back()+i);
        }
        
    }
    
    int sumRange(int left, int right) {
        return a[right+1]-a[left];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */