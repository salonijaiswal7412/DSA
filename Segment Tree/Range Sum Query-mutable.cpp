class Segment{
    public:
    vector<int> seg;
    Segment(int n){
        seg.resize(4*n,0);
    }

    void build(int i,int l,int h,vector<int>& nums){
        if(l==h) {
            seg[i]=nums[l];
            return;
        }
        int m=(l+h)/2;
        build(2*i+1,l,m,nums);
        build(2*i+2,m+1,h,nums);

        seg[i]=seg[2*i+1]+seg[2*i+2];
    } 

    void update(int i,int l,int h,int pos,int val){
        if(l==h){
            seg[i]=val;
            return;
        }

        int m=(l+h)/2;
        if(pos<=m){
            update(2*i+1,l,m,pos,val);
        }
        else{
            update(2*i+2,m+1,h,pos,val);
        }

        seg[i]=seg[2*i+1]+seg[2*i+2];
    }

    int query(int i,int l,int h,int low,int high){
        if(h<low || high<l) return 0;
        if(low<=l && h<=high) return seg[i];

        int m=(l+h)/2;
        return query(2*i+1,l,m,low,high)+query(2*i+2,m+1,h,low,high);
    }
};
class NumArray {
public:
Segment t;
int n;
    NumArray(vector<int>& nums):t(nums.size())  {
        n=nums.size();
        t.build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        t.update(0,0,n-1,index,val);
        
    }
    
    int sumRange(int left, int right) {
        return t.query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
