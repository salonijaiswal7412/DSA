class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=0;
        double maxd=0.0;
        for(auto i:dimensions){
            int l=i[0],b=i[1];
            if(sqrt(l*l+b*b)>maxd || sqrt(l*l+b*b)==maxd && l*b>ans){
                maxd=sqrt(l*l+b*b );
                ans=l*b;
            }
        }
        return ans;
        
    }
};
