//using merge sort
class Solution {
public:
    void merge(vector<int>& nums,int l,int mid,int h){
        int m=mid-l+1;
        int n=h-mid;
        int L[m],R[n];
        for(int i=0;i<m;i++){
            L[i]=nums[l+i];
        }
        for(int i=0;i<n;i++){
            R[i]=nums[mid+i+1];
        }
        int i=0,j=0,k=l;
        while(i<m && j<n){
            if(L[i]<=R[j]){
                nums[k++]=L[i++];
            }
            else{
                nums[k++]=R[j++];
            }
        }
        while(i<m) nums[k++]=L[i++];
        while(j<n) nums[k++]=R[j++];
    }
    int mergesort(vector<int>& nums,int l,int h){
        if(l<h){
            int m=(l+h)/2;
            int c=mergesort(nums,l,m)+mergesort(nums,m+1,h);
            
            int j=m+1;
            for(int i=l;i<=m;i++){
                while(j<=h && nums[i]>2LL*nums[j]){
                    j++;
                }
                c+=j-(m+1);
            }
            merge(nums,l,m,h);
            return c;
        }
        else return 0;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
        
    }
};
