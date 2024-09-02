//print the elements in the given no of row in the pascal triangle
//Brute force approach
//time complexity=O(n*r)
class Solution {
public:
    long long ncr(int n,int r){
        long long a=1;
        for(int i=0;i<r;i++){
            a*=(n-i);
            a/=(i+1);
        }
        return a;
    }
    vector<int> getRow(int r) {
        vector<int>ans;
        for(int i=1;i<=r+1;i++){
            long long t=ncr(r+1-1,i-1);
            ans.push_back(t);
        }
        return ans;
        
    }
};

//approach using DP
//time complexity O(r)
class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> ans;
        long long a=1;
        ans.push_back(a);
        for(int i=1;i<=r;i++){
           a*=(r-i+1);
           a/=i;
           ans.push_back(a);
        }
        return ans;
        
    }
};
