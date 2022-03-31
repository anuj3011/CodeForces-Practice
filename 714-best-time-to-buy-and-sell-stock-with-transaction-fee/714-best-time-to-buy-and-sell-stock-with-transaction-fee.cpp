class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int aheadBuy,aheadNotBuy,currBuy,currNotBuy;
        aheadBuy=aheadNotBuy=0;
        for(int i=prices.size()-1;i>=0;i--){
            currBuy= max(-prices[i] + aheadNotBuy, aheadBuy);
            currNotBuy= max(prices[i]-fee + aheadBuy,  aheadNotBuy);
            aheadBuy=currBuy;
            aheadNotBuy=currNotBuy;
        }
        return aheadBuy;
    }
};