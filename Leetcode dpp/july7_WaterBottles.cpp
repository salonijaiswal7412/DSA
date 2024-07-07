class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int s=numBottles;
        while(numBottles>=numExchange){
            int newb=numBottles/numExchange;
            int remb=numBottles%numExchange;
            s+=newb;
            numBottles=newb+remb;
        }
        return s;
        
        
        
    }
};
