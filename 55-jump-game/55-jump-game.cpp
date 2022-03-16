class Solution {
public:
    bool f(int i, vector<int> &nums,vector<int> &dp){
        if(i>=nums.size()) return false;
        if(i==nums.size()-1) return true;
        if(nums[i]==0) return false;
        if(dp[i]!=-1) return dp[i];
        for(int jump=nums[i];jump>0;jump--){
            if(f(i+jump,nums,dp)){
                dp[i]=true;
                return true;
            }
        }
        dp[i]=false;
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return f(0,nums,dp);
    }
};