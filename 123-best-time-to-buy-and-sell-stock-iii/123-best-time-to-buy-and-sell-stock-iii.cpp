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
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n, vector<int>(2, vector<int>(3,-1)));
        // memset(dp,-1,sizeof(dp));
        // return f(0,1,2,prices); //0 is index, 1 is start from buy, 2 is at max 2 transactions;
        
        // memset(dp,0,sizeof(dp));
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<3;cap++){
                    if(buy){
                        curr[buy][cap]=max(-prices[i] + after[0][cap],
                                   after[1][cap]);
                    }else{
                        curr[buy][cap]=max(prices[i] + after[1][cap-1],
                                   after[0][cap]);
                    }
                    after=curr;
                }
            }
        }
        return after[1][2];
    }
};