class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int ind=-1;
        int n=a.size();
        //step 1 finding the breakpoint
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]<a[i+1]){
                ind=i;
                break;
            }
        }
       
        if(ind!=-1){
        //step 2 finding just max no than breakpt
        for(int i=n-1;i>ind;i--){
            if(a[i]>a[ind])
            {
                swap(a[i],a[ind]);
                break;
            }
        }
        }
        //step 3 reverse array
        reverse(a.begin()+ind+1,a.end());
        
    }

};
