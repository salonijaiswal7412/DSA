//using priority_queue for returning min order
#include<bits/stdc++.h>
using namespace std;

vector<int> findOrder(int n, vector<vector<int>> pre) {
    
    vector<vector<int>> v(n);
    for(auto i:pre){
        v[i[1]].push_back(i[0]);
    }
    priority_queue<int,vector<int>,greater<int>> q;
    vector<int> deg(n,0);
    for(int i=0;i<n;i++){
        for(auto j:v[i]){
            deg[j]++;
        }
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(deg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int f=q.top();
        ans.push_back(f);
        q.pop();
        for(auto i:v[f]){
            if(--deg[i]==0){
                q.push(i);
            }
        }
    }
    return ans.size()==n?ans:vector<int>();
}