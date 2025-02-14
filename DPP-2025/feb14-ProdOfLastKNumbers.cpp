class ProductOfNumbers {
public:
    vector<int> pre;
    int n=0;
    ProductOfNumbers() {
        pre.push_back(1);
        n=0;
        
    }
    
    void add(int num) {
        if(num==0){
            pre={1};
            n=0;
        }
        else{
            pre.push_back(pre[n++]*num);
        }
        
    }
    
    int getProduct(int k) {
        if(k>n) return 0;
        return pre[n]/pre[n-k];
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
