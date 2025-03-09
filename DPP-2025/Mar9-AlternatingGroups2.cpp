//sliding window
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        int ans=0,l=0,r=1;
        int n=colors.size();
        while(r<n){
            if(colors[r]==colors[r-1]){
                l=r++;
                continue;
            }
            r++;
            if(r-l<k) continue;
            ans++;
            l++;
        }
        return ans;
        
    }
};
