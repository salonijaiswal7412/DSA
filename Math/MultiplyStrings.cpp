class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"|| num2=="0") return "0";
        int m=num1.size(),n=num2.size();
        vector<int> nums(m+n,0);

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int s=mul+nums[i+j+1];
                nums[i+j+1]=s%10;
                nums[i+j]+=s/10;
            }
        }
        int i=0;
        string ans;
        while(i<nums.size() && nums[i]==0) i++;
        while(i<nums.size()){
            ans.push_back(nums[i++]+'0');
        }
        return ans;

        
    }
};
