class Solution {
public:
    int f(int n, int m,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(n==0 && m==0){
            return grid[0][0];
        }
        if(n<0 || m<0) return 1e3;
        if(dp[n][m]!=-1) return dp[n][m];
        int left=f(n-1,m,grid,dp) +grid[n][m];
        int up=f(n,m-1,grid,dp) +grid[n][m];
        return dp[n][m]=min(left,up);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        // int n=grid.size();
        // int m=grid[0].size();
        // vector<vector<int>> dp(n,vector<int> (m,-1));
        // return f(n-1,m-1,grid,dp);
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0) dp[i][j]=grid[i][j];
                else{
                    int left=grid[i][j],up=grid[i][j];
                    if(i>0) left+=dp[i-1][j];
                    else left+=1e3;
                    if(j>0) up+=dp[i][j-1];
                    else up+=1e3;
                    dp[i][j]=min(left,up);
                }
            }
        }
        return dp[n-1][m-1];
    }
};