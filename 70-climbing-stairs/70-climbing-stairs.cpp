class Solution {
public:
    int countWays(int n,vector<int> &dp){ //Memoization
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1) return dp[n];
        dp[n-1]=countWays(n-1,dp);
        dp[n-2]=countWays(n-2,dp);
        return dp[n]=dp[n-1]+dp[n-2];
    }
    int countWays_tabulation(int n,vector<int> &dp){
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return countWays(n,dp); //memoization
        // return dp[n];
        
        vector<int> dp(n+1);
        return countWays_tabulation(n,dp);
    }
};