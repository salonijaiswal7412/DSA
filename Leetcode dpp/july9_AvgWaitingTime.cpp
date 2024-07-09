class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int l=customers.size();
        double wait=customers[0][1];
        int prev=customers[0][0]+customers[0][1];
        for(int i=1;i<l;i++){
            int start=customers[i][0];
            int cook=max(start,prev);
            int end=cook+customers[i][1];
            prev=end;
            wait+=end-customers[i][0];

        }
        return wait/l;
        
    }
};
