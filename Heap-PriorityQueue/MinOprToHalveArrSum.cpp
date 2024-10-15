class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double s=0;
        for(auto i:nums){
            s+=i;
            pq.push(i);
        }
        double target=s/2.0;
        int ans=0;
        while(s>target){
            double temp=pq.top()/2.0;
            pq.pop();
            s-=temp;
            pq.push(temp);

            ans++;
        }
        return ans;
        
    }
};