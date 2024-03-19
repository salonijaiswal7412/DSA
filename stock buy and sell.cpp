class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP=0;
        int minE=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            minE=min(minE,prices[i]);
            maxP=max(maxP,prices[i]-minE);
        }
        return maxP;
        
    }
};
