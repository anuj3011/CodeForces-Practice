class Solution {
public:
     int countWays(int ind,vector<int> a, vector<int> &dp){
        if(ind>=a.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int left=countWays(ind+1,a,dp) + a[ind];
        int right=countWays(ind+2,a,dp) + a[ind];
        return dp[ind]=min(left,right);
    }
    
    int minCostClimbingStairs(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        int c1= countWays(1,nums,dp);
        int c2=countWays(0,nums,dp);
        return min(c1,c2);
    }
};