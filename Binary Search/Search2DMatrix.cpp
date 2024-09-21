class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int r=0,c=n-1;
        while(r<m && c>-1){
            int temp=matrix[r][c];
            if(temp==target) return true;
            if(temp<target) r++;
            else c--;

        }
        return false;
        
    }
};