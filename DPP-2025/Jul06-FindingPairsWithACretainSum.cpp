class FindSumPairs {
private:
vector<int> nums1,nums2;
unordered_map<int,int> m;
public:
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
        for(int i:nums2){
            m[i]++;
        }
    }
    
    void add(int index, int val) {
        m[nums2[index]]--;
        nums2[index]+=val;
        m[nums2[index]]++;
        
    }
    
    int count(int tot) {
        int ans=0;
        for(int i:nums1){
            int t=tot-i;
            ans+=m[t];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
