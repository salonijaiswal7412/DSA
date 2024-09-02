//return vector containing all elements which occur >n/3 times in the array,at max an array can have 2 such elements
//time O(n^2),space O(1)
//Brute force approach
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(ans.size()==0|| ans[0]!=nums[i]){
                int c=0;
                for(int j=0;j<nums.size();j++){
                    if(nums[i]==nums[j])c++;
                }
                if(c>nums.size()/3)
                ans.push_back(nums[i]);

            }
            if(ans.size()==2)break;
        }
        return ans;
        
    }
};

//approach using hashmap
//time:O(nlogn) space O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        map<int,int>m;
        int min=(nums.size()/3)+1;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]==min)
            ans.push_back(nums[i]);
        }
        return ans;
        
    }
};

//optimal sol: using Moore's voting algo
//time :O(2n) space:O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int c1=0,c2=0,a=INT_MIN,b=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(c1==0 && b!=nums[i]){
                c1++;
                a=nums[i];

            }
            else if(c2==0 && a!=nums[i]){
                c2++;
                b=nums[i];
            }
            else if(a==nums[i])c1++;
            else if(b==nums[i])c2++;
            else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(int i=0;i<nums.size();i++){
            if(a==nums[i])c1++;
            if(b==nums[i])c2++;
        }
        int min=(nums.size()/3)+1;
        if(c1>=min) ans.push_back(a);
        if(c2>=min) ans.push_back(b);
        return ans;
        
    }
};