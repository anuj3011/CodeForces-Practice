class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int transactions= 2*k;
        vector<int> curr(transactions+1,0),ahead(transactions+1,0);
        for(int ind=prices.size()-1;ind>=0;ind--){
            for(int trans=transactions-1;trans>=0;trans--){
                if(trans%2==0){
                    curr[trans]=max(-prices[ind] + ahead[trans+1],ahead[trans]);
                }else{
                    curr[trans]=max(prices[ind] + ahead[trans+1],ahead[trans]);
                }
                ahead=curr;
            }
        }
      return ahead[0]; 
    }
};