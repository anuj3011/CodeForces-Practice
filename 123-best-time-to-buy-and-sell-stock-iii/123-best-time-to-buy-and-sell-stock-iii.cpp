class Solution {
public:
    // int dp[100005][2][3];
    
    // int f(int ind, int buy, int cap, vector<int> &prices){ memoization
    //     if(cap==0) return 0;
    //     if(ind==prices.size()) return 0;
    //     if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
    //     int profit=0;
    //     if(buy){
    //         profit= max(-prices[ind] + f(ind+1,0,cap,prices),
    //                     f(ind+1,1,cap,prices));
    //     }else{
    //         profit= max(prices[ind] + f(ind+1,1,cap-1,prices),
    //                      f(ind+1,0,cap,prices));
    //     }
    //     return dp[ind][buy][cap]=profit;
    // }
    
//     int maxProfit(vector<int>& prices) { //tabulation memory optimised
//         int n=prices.size();
//         // vector<vector<vector<int>>> dp(n, vector<int>(2, vector<int>(3,-1)));
//         // memset(dp,-1,sizeof(dp));
//         // return f(0,1,2,prices); //0 is index, 1 is start from buy, 2 is at max 2 transactions;
        
//         // memset(dp,0,sizeof(dp));
//         vector<vector<int>> after(2,vector<int>(3,0));
//         vector<vector<int>> curr(2,vector<int>(3,0));
        
//         for(int i=n-1;i>=0;i--){
//             for(int buy=0;buy<=1;buy++){
//                 for(int cap=1;cap<3;cap++){
//                     if(buy){
//                         curr[buy][cap]=max(-prices[i] + after[0][cap],
//                                    after[1][cap]);
//                     }else{
//                         curr[buy][cap]=max(prices[i] + after[1][cap-1],
//                                    after[0][cap]);
//                     }
//                     after=curr;
//                 }
//             }
//         }
//         return after[1][2];
//     }
    
    int f_n4(int ind, int trans,vector<int> &prices, vector<vector<int>> &dp){
        if(ind==prices.size() || trans==4)
            return 0;
        if(dp[ind][trans]!=-1) return dp[ind][trans];
        if(trans%2==0){
            return dp[ind][trans]=max(-prices[ind] + f_n4(ind+1,trans+1,prices,dp),
                       f_n4(ind+1,trans,prices,dp));
        }else{
            return dp[ind][trans]=max(prices[ind] + f_n4(ind+1,trans+1,prices,dp),
                       f_n4(ind+1,trans,prices,dp));
        }
    }
    
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