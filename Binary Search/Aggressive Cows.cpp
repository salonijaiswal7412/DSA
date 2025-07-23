// User function Template for C++

class Solution {
  public:
    bool canPlace(int cows,int k,vector<int>& stalls){
        int n=stalls.size(),c=1,last=stalls[0];
        
        for(int i=0;i<n;i++){
            if(stalls[i]-last>=k){
                c++;
                last=stalls[i];
            }
            if(c>=cows) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int l=1,h=stalls[n-1]-stalls[0];
        
        while(l<=h){
            int m=(l+h)/2;
            if(canPlace(k,m,stalls)){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return h;
    }
};
