class Solution {
public:
      bool isValid(vector<vector<char>>& board,char c,int row, int col){
        for(int i=0;i<9;i++){
            if(i!=row && board[i][col]==c){
                return false;
            }
                
            if(i!=col && board[row][i]==c){
                return false;
            }
            int x=3*(row/3)+(i/3);
            int y=3*(col/3) +i%3;
            if(x!=row && y!=col && board[x][y]==c)
                return false;
            
        }
        return true;
    }
    

    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    if(!isValid(board,board[i][j],i,j))
                        return false;
                }
            }
        }
        return true;
    }
};