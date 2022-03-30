class Solution {
public:
    int f(int ind, bool buy, vector<int> &prices,
            vector<vector<int>> &dp){
        if(ind==prices.size())
            return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=INT_MIN;
        if(buy){
            int take= -prices[ind] + f(ind+1,false,prices,dp);
            int notTake= 0+ f(ind+1, true, prices,dp);
            profit=max(take,notTake);
        }
        else{
            int sellHere= prices[ind] + f(ind+1,true, prices,dp);
            int notSellHere = 0+ f(ind+1,false,prices,dp);
            profit=max(sellHere,notSellHere);
        }
        return dp[ind][buy] =profit;
    }
    
    int maxProfit(vector<int>& prices){
        vector<vector<int>> dp(prices.size(), vector<int> (2,-1));
        return f(0,true,prices,dp);
    }
};