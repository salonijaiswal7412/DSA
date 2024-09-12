CountSubaaraySumK.cpp
//brute force approach
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int c=0;
        for(int i=0;i<nums.size();i++){
            int s=0;
            for(int j=i;j<nums.size();j++){
                s+=nums[j];
                if(s==k)c++;
            }
        }
        return c;
        
    }
};

//approach using hashmap
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int s=0,c=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            c+=m[s-k];
            m[s]+=1;
        }
        return c;
        
    }
};