class Solution {
public:
    int check(vector<vector<int>>& temp,int i,int j){
        int c=0;
        if(i>0) if(temp[i-1][j]==1)c++;
        if(i<temp.size()-1) if(temp[i+1][j]==1) c++;
        if(j>0) if(temp[i][j-1]==1) c++;
        if(j<temp[0].size()-1) if(temp[i][j+1]==1)c++;
        if(i>0 && j>0) if(temp[i-1][j-1]==1) c++;
        if(i>0 && j<temp[0].size()-1) if(temp[i-1][j+1])c++;
        if(i<temp.size()-1 && j>0) if(temp[i+1][j-1]==1) c++;
        if(i<temp.size()-1 && j<temp[0].size()-1) if(temp[i+1][j+1]==1)c++;

        return c;


    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp=board;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int nbr=check(temp,i,j);
                if(temp[i][j] && nbr<2) board[i][j]=0;
                else if(temp[i][j] &&(nbr==2 || nbr==3)) board[i][j]=1;
                else if(temp[i][j] && nbr>3) board[i][j]=0;
                else if(!temp[i][j] && nbr==3) board[i][j]=1;
            }
        }
        
    }
};
