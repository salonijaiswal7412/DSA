vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    int m=INT_MIN;
    vector<int> ans;
    
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]>m){
           ans.push_back(a[i]);
        }
        m=max(m,a[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
