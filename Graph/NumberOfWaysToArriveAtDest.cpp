class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        vector<int> count(n,0);
        vector<vector<pair<long long,int>>> v(n);
        for(auto i:roads){
            v[i[0]].push_back({i[2],i[1]});
            v[i[1]].push_back({i[2],i[0]});
        }
        vector<long long > dis(n,LLONG_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        q.push({0,0});
        dis[0]=0;
        count[0]=1;
        while(!q.empty()){
            auto f=q.top();q.pop();
            long long w=f.first;
            int node=f.second;
            for(auto i:v[node]){
                long long wt=i.first;
                int nbr=i.second;
                if(w+wt<dis[nbr]){
                    dis[nbr]=w+wt;
                    count[nbr]=count[node];
                    q.push({dis[nbr],nbr});
                    
                }
                else if(w+wt==dis[nbr]){
                    count[nbr]=(count[node]+count[nbr])%mod;
                }
            }

        }
        return count[n-1];
        
    }
};
