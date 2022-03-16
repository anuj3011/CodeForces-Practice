class Solution {
public:
    int f(int i, vector<int> &nums,vector<int> &dp){
        if(i>=nums.size()) return 1e5;
        if(i==nums.size()-1) return 0;
        if(nums[i]==0) return 1e5;
        if(dp[i]!=-1) return dp[i];
        int mini=1e5;
        for(int jump=1;jump<=nums[i];jump++){
            int nextMove= 1+f(i+jump,nums,dp);
            mini=min(mini,nextMove);
        }
        return dp[i]=mini;
    }
    
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,dp);
    }
};