class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto incr=[](double p,double t){
            return (p+1)/(t+1)-p/t;
        };
        double s=0.0;
        priority_queue<pair<double,pair<int,int>>> pq;
        for(const auto& i:classes){
            int p=i[0],t=i[1];
            s+=(double)p/t;
            pq.push({incr(p,t),{p,t}});
        }
        for(int i=0;i<extraStudents;i++){
            auto [curr,data]=pq.top();pq.pop();
            int p=data.first,t=data.second;
            
            s-=(double)p/t;
            p++;
            t++;
            s+=(double)p/t;

            pq.push({incr(p,t),{p,t}});
        }
        return s/classes.size();

     
    }
};
