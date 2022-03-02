class Solution {
public:
    int countWays(int m,int n, vector<vector<int>> &dp){
        if(n==0 && m==0){
            return 1;
        }
        if(n<0 || m<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int prevRow=countWays(m-1,n,dp);
        int prevCol=countWays(m,n-1,dp);
        return dp[m][n] =prevRow + prevCol;
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int> (n,-1));
        // return countWays(m-1,n-1,dp);
        vector<vector<int>> dp(m,vector<int> (n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else{
                    int left=0,top=0;
                    if(i>0) left=dp[i-1][j];
                    if(j>0) top=dp[i][j-1];
                    dp[i][j]=left+top;
                }
            }
        }
        return dp[m-1][n-1];
    }
};