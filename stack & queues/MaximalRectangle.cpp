//using concept of largest rec in histogram using nse-pse-1
class Solution {
public:
    vector<int> nextsmaller(vector<int>& a){
        int n=a.size();
        vector<int> ans(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && a[i]<=a[s.top()])
            s.pop();
            ans[i]=s.empty()?a.size():s.top();
            s.push(i);

        }
        return ans;
    }
    vector<int> prevsmaller(vector<int>& a){
        int n=a.size();
        vector<int> ans(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && a[i]<=a[s.top()])
            s.pop();

            ans[i]=s.empty()?-1:s.top();
            s.push(i);
        }
        return ans;
    }
    int solve(vector<int> & a){

        int n=a.size();
        long long int ans=0;
        vector<int> nse=nextsmaller(a);
        vector<int>pse=prevsmaller(a);
        for(int i=0;i<n;i++){
            long long int width=nse[i]-pse[i]-1;
            long long int temp=(long long int)a[i]*width;
            ans=max(ans,temp);
        }
        return ans;



    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> histogram(matrix[0].size());
        int ans=-1e9;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<histogram.size();j++){
                if(matrix[i][j]=='1'){
                    histogram[j]++;
                }
                else histogram[j]=0;
            }
            ans=max(ans,solve(histogram));
        }
        return ans;

        
    }
};
