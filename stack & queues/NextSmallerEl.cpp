#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans(n,-1);
    stack<int> s;
    for(int i=0;i<n;i++){
        if(s.empty()){
            s.push(i);
            continue;
        }
        while(!s.empty() && arr[s.top()]>arr[i]){
            ans[s.top()]=arr[i];
            s.pop();
        }
        s.push(i);
    }
    return ans;
}