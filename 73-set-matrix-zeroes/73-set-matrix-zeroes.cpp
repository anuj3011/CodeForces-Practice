class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(!matrix[i][j]){
                    v.push_back({i,j});
                }
            }
        }
        for(auto it: v){
            int i=it.first;
            int j=it.second;
            for(int I=0;I<matrix.size();I++)
                matrix[I][j]=0;
            for(int J=0;J<matrix[0].size();J++)
                matrix[i][J]=0;
        }
    }
};