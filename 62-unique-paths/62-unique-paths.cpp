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
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return countWays(m-1,n-1,dp);
        
    }
};