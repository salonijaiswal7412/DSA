class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n=a.size();
        if(n==0)return 0;
        sort(a.begin(),a.end());
        int c=0,longest=1;
        int last=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(a[i]-1==last){
                c++;
                last=a[i];
            }
            else if(a[i]!=last){
                c=1;
                last=a[i];
            }
            longest=max(longest,c);
        }
        return longest;
    }
};
