class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0],sell=1,profit=0,res=0;
        for(int i=1;i<prices.size();i++){
            if(buy>prices[i]){
                buy=prices[i];
            }else{
                sell=prices[i];
                profit=sell-buy;
            }
            res=max(res,profit);
        }
        return res;
    }
};