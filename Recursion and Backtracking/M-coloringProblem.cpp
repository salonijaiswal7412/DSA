bool isSafe(int node,int c,int m,int n,vector<int>& color,vector<vector<int>>&mat){
    for(int i=0;i<n;i++){
        if(mat[node][i] && color[i]==c){
            return false;
        }
    }
    return true;
}
bool solve(int node,int m,int n,vector<int>& color,vector<vector<int>>& mat){
    if(node==n) return true;

    for(int i=1;i<=m;i++){
        if(isSafe(node,i,m,n,color,mat)){
            color[node]=i;
            if(solve(node+1,m,n,color,mat)) return true;
            color[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n=mat.size();
    vector<int> color(n,0);
    return (solve(0,m,n,color,mat))? "YES":"NO";
}
