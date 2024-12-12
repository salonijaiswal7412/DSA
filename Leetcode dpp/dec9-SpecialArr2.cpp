class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> pre(n);
        pre[0]=1;
        for(int i=1;i<n;i++){
            if((nums[i] & 1)!=(nums[i-1] & 1)){
                pre[i]=pre[i-1]+1;
            }
            else{
                pre[i]=1;
            }
        }
        vector<bool> ans;
        for(auto i :queries){
            int l=i[0],h=i[1];
            ans.push_back(pre[h]>=(h-l+1));
        }
        return ans;
        
    }
};
