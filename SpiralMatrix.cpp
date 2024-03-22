vector<int> spiralMatrix(vector<vector<int>>&a) {
    // Write your code here.
    int m=a.size();
    int n=a[0].size();
    int top=0,left=0;
    vector<int> ans;
    int right=n-1,bottom=m-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++)
        {
            ans.push_back(a[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(a[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(a[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(a[i][left]);
            }
            left++;
        }
    }
    return ans;
}
