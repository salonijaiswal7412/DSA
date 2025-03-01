class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<int> indegree(num,0);
        vector<vector<int>> v(num);
        for(auto& i:pre){
            v[i[0]].push_back(i[1]);
        }
        for(int i=0;i<num;i++){
            for(auto j:v[i]){
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<num;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(auto i:v[f]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        for(auto i:indegree){
            if(i!=0) return false;
        }
        return true;

        
    }
};
