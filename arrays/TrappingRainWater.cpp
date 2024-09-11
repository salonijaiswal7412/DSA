//using extra space
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> rm(n);
        vector<int> lm(n);
        lm[0]=height[0],rm[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            lm[i]=max(height[i],lm[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rm[i]=max(height[i],rm[i+1]);

        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(lm[i],rm[i])-height[i];
        }
        return ans;
        
    }
};


//two pointer approach
class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int l=0,r=n-1;
        int ans=0,maxl=INT_MIN,maxr=INT_MIN;

        while(l<=r){
            if(h[l]<=h[r]){
                if(h[l]>=maxl){
                    maxl=h[l];
                }
                else{
                    ans+=maxl-h[l];
                }
                l++;
            }
            else{
                if(h[r]>=maxr){
                    maxr=h[r];
                }
                else{
                    ans+=maxr-h[r];
                }
                r--;
            }
        }
        return ans;
        
    }
};