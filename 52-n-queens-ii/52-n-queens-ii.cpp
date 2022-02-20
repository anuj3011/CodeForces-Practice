class Solution {
public:
    void queens(int col, int &ans, vector<string> &board, vector<int>                        &leftRow,vector<int> &lowerDiagonal, vector<int> &upperDiagonal, int n){
        if(col==n){
            ans++;
            return;
        }
        for(int row=0;row<n;row++){
            if(!leftRow[row] && !lowerDiagonal[row+col] && !upperDiagonal[n-1 +col-row]){
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1 +col-row]=1;
                board[row][col]='Q';
                queens(col+1,ans,board,leftRow,lowerDiagonal,upperDiagonal,n);
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1 +col-row]=0;
                board[row][col]='.';
            }
        }
        
    }
    
    int totalNQueens(int n) {
        int ans=0;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        
        vector<int> leftRow(n,0), lowerDiagonal(2*n-1,0),upperDiagonal(2*n-1,0);
        queens(0,ans,board,leftRow,lowerDiagonal,upperDiagonal,n);
        return ans;
    }
};