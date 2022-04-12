class Solution {
public:
    int n,m;
    
    bool isValid(int x,int y){
        if(x<0 || y<0 || x>=m || y>=n)
            return false;
        return true;
    }
    void nextState(vector<vector<int>>& board,int x,int y,vector<vector<int>> &temp){
        int count=0;
        int cx[]={-1,-1,-1,0,0,1,1,1};
        int cy[]={-1,0,1,-1,1,-1,0,1};
        for(int i=0;i<8;i++){
            if(isValid(cx[i]+x,cy[i]+y)){
                if(board[cx[i]+x][cy[i]+y])
                    count++;
            }
        }
        if(board[x][y]){
            if(count<2) temp[x][y]=0;
            else if(count<=3) temp[x][y]=1;
            else temp[x][y]=0;
        }else{
            if(count==3) temp[x][y]=1;
        }
        
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        m=board.size();
        n=board[0].size();
        vector<vector<int>> temp;
        temp=board;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                nextState(board,i,j,temp);
        board=temp;
    }
};