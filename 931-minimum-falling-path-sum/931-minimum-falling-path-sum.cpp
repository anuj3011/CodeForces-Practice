class Solution {
public:
    int calSum(vector<vector<int>>& matrix, int i, int j,
              vector<vector<int>> &dp){
        if(i==matrix.size()){
            return 0;
        }
        if(i<0 || j<0 || j>=matrix.size())
            return 1e5;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=matrix[i][j],left=matrix[i][j];
        if(j>0)
            left+= calSum(matrix,i+1,j-1,dp);
        else 
            left+=1e5;
        int below=matrix[i][j] + calSum(matrix,i+1,j,dp);
        if(j<matrix.size())
            right+= calSum(matrix,i+1,j+1,dp);
        else right+=1e5;
        return dp[i][j]= min(left, min(below,right));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum=INT_MAX;
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
          int sum=calSum(matrix,0,j,dp);
            minSum=min(sum,minSum);
        }
        return minSum;
    }
};