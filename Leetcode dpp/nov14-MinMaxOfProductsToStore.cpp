class Solution {
public:
    bool canDist(vector<int>& arr,int maxProd,int stores){
        int need=0;
        for(auto i: arr){
            need+=ceil((double)i/maxProd);
            if(need>stores) return false;
        }
        return need<=stores;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1;
        int h=*max_element(quantities.begin(),quantities.end());
        int ans=h;

        while(l<=h){
            int m=l+(h-l)/2;
            if(canDist(quantities,m,n)){
                ans=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
        
    }
};