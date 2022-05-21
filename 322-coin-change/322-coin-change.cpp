class Solution {
public:
    int f(int ind, int amount, vector<int> &coins,vector<vector<int>> &dp){
        if(ind==0){
          if(amount%coins[0]==0) return amount/coins[0];
          else return 1e7;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notPick= f(ind-1,amount,coins,dp);
        int pick=INT_MAX;
        if(coins[ind]<=amount){
            pick=1+ f(ind,amount-coins[ind],coins,dp); //staying at same index as infinite supply
        }
        return dp[ind][amount]=min(pick,notPick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=f(coins.size()-1,amount,coins,dp);
        return (ans>1e5)?-1:ans;
    }
};