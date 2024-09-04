class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP=0;
        int l=prices.size();
        int start=prices[0];
        for(int i=1;i<l;i++){
            if(prices[i]>start)
            maxP+=(prices[i]-start);
            start=prices[i];
        }
        return maxP;
        
    }
};