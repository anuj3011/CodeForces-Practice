class Solution {
public:
    int countSubset(int ind, int target, vector<int> &nums,                                 vector<vector<int>> &dp){
         if(ind == 0){
        if(target==0 && nums[0]==0)
            return 2;
        if(target==0 || target == nums[0])
            return 1;
        return 0;
    }
        if(ind==0) return(nums[0]==target);
        if(dp[ind][target]!=-1) return dp[ind][target];
        int notPick=countSubset(ind-1,target,nums,dp);
        int pick=0;
        if(nums[ind]<=target){
            pick=countSubset(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=pick+notPick;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum=0;
        for(auto it:nums)
            totSum+=it;
        if((totSum-target)%2!=0){
            return 0;
        }
        if(totSum-target<0) return 0;
        int s2=(totSum-target)/2;
        vector<vector<int>> dp(nums.size(),vector<int>(s2+1,-1));
        return countSubset(nums.size()-1,s2,nums,dp);
    }
};