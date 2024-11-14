class Solution {
public:
    bool check(int col,int row,vector<string>board,int n){
        int r=row,c=col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;c--;
        }
        r=row,c=col;
        while(c>=0){
            if(board[r][c]=='Q') return false;
            c--;
        }
        r=row,c=col;
        while(r<n && c>=0){
            if(board[r][c]=='Q') return false;
            r++;c--;
        }
        return true;
    }
    void solve(int c,vector<string>& board,vector<vector<string>> & ans,int n){
        if(c==n){
            ans.push_back(board);
            return;
        }
        for(int r=0;r<n;r++){
            if(check(c,r,board,n)){
                board[r][c]='Q';
                solve(c+1,board,ans,n);
                board[r][c]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
        
    }
};