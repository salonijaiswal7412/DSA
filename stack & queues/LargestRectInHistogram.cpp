class Solution {
public:
    vector<int> nse(vector<int>& a){
        stack<int> s;
        vector<int> ans(a.size());
        for(int i=a.size()-1;i>=0;i--){
            while(!s.empty() && a[s.top()]>=a[i]){
                s.pop();
            }
            ans[i] = s.empty() ? a.size() : s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> pse(vector<int>& a){
        stack<int> s;
        vector<int> ans(a.size());
        for(int i=0;i<=a.size()-1;i++){
            while(!s.empty() && a[s.top()]>=a[i]){
                s.pop();
            }
           ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        long long int ans=0;
        vector<int>next=nse(heights);
        vector<int>prev=pse(heights);
        for(int i=0;i<heights.size();i++){
            
            long long int width = next[i] - prev[i] - 1;
            long long int c = (long long int)heights[i] * width;
            ans = max(ans, c);
        }
        return ans;
        
    }
};