class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i:digits){
            m[i]++;
        }
        for(int i=100;i<=999;i+=2){
            unordered_map<int,int>temp;
            int x=i;
            while(x){
                temp[x%10]++;
                x/=10;
            }
            bool flag=true;
            for(auto [x,y]:temp){
                if(temp[x]>m[x]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.push_back(i);
            }
        }
        return ans;

        
    }
};
