class Solution {
public:
    int countWays(int n,vector<int> &dp){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1) return dp[n];
        dp[n-1]=countWays(n-1,dp);
        dp[n-2]=countWays(n-2,dp);
        return dp[n]=dp[n-1]+dp[n-2];
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return countWays(n,dp);
        // return dp[n];
    }
};