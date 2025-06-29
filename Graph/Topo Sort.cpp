//BFS-Kahn's Algo
#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)  {
    // Write your code here
    vector<int> indeg(n,0);
    vector<vector<int>> v(n);

    for(auto i:edges){
        v[i[0]].push_back(i[1]);
        indeg[i[1]]++;
    }

    queue<int> q;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(!indeg[i]){
            q.push(i);
        }
    }

    while(!q.empty()){
        int f=q.front();
        q.pop();
        ans.push_back(f);
        for(int i:v[f]){
            if(--indeg[i]==0){
                q.push(i);
            }
        }
    }
    return ans;
}


//DFS
#include <bits/stdc++.h> 
void dfs(int n,vector<vector<int>>& v,vector<int>& vis,stack<int>& s){
    vis[n]=1;

    for(int i:v[n]){
        if(!vis[i]){
            dfs(i,v,vis,s);
        }
    }
    s.push(n);
    
}
vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)  {
    // Write your code here
    vector<int> vis(n,0);
    stack<int> s;

    vector<vector<int>> v(n);
    for(auto i:edges){
        v[i[0]].push_back(i[1]);
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,v,vis,s);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
