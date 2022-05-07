class Solution {
public:
    int f(int ind, set<int> &s, vector<int> &costs,vector<int>&dp){
        if(ind<=0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int res=0;
        if(s.find(ind)!=s.end()){
            int buy30= costs[2] + f(ind-30,s,costs,dp);
            int buy7= costs[1] + f(ind-7,s,costs,dp);
            int buy1= costs[0] + f(ind-1,s,costs,dp);
            res= min(buy30,min(buy7,buy1));
        }else{
            res=f(ind-1,s,costs,dp);
        }
        return dp[ind]=res;
    }
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int lastDay=days[n-1];
        set<int> s;
        for(auto it: days) s.insert(it);
        vector<int> dp(lastDay+1,-1);
        return f(lastDay,s,costs,dp);
    }
};