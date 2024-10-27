class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[i][j]==1){
                    matrix[i][j]+=min(matrix[i-1][j],min(matrix[i][j-1],matrix[i-1][j-1]));
                }
            }

        }
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans+=matrix[i][j];
            }
        }
        return ans;

        
    }
};
