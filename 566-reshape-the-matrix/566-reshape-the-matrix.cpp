class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size();
        int m=mat[0].size();
        if(r*c!=m*n)
            return mat;
        vector<vector<int>> res(r,vector<int>(c));
        int x=0,y=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[x][y]=mat[i][j];
                if(y!=c-1){     //to check if reached end of column in new matrix
                    y++;        //if no move ahead in same column
                }else{
                    y=0;        //if yes set column to 0
                    x++;        //and move to next row;
                }
            }
        }
        return res;
    }
};