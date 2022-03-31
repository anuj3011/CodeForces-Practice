class Solution {
public:
   
    
    int maxProfit(vector<int>& prices){ //n*4 memoization
        // vector<vector<int>> dp(prices.size(), vector<int>(4,-1));
        // return f_n4(0,0,prices,dp); //ind and transaction as 0
        
        vector<vector<int>> dp(prices.size()+1, vector<int>(5,0));
        for(int ind=prices.size()-1;ind>=0;ind--){
            for(int trans=3;trans>=0;trans--){
                if(trans%2==0){
                    dp[ind][trans]=max(-prices[ind] + dp[ind+1][trans+1],dp[ind+1][trans]);
                }else{
                    dp[ind][trans]=max(prices[ind] + dp[ind+1][trans+1],dp[ind+1][trans]);
                }
            }
        }
      return dp[0][0];  
    }
    
};