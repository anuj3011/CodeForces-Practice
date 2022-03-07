class Solution {
public:
//     bool checkSubset(vector<int> nums,vector<vector<int>> &dp,
//                     int target, int ind){
//         if(target==0) return true;
//         if(ind==0) return(nums[0]==target);
//         if(dp[ind][target]!=-1) return dp[ind][target];
//         bool notTake= checkSubset(nums,dp,target,ind-1);
//         bool take=false;
//         if(target >= nums[ind]){
//             take=checkSubset(nums,dp,target-nums[ind],ind-1);
//         }
//         return dp[ind][target]= take||notTake;
//     }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it: nums) sum+=it;
        if(sum&1) return false;
        int target=sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return fun(nums.size()-1,target,nums,dp);
    }
    //     bool canPartition(vector<int>& nums) {
    //     int n = nums.size();
    //     int total = accumulate(nums.begin(),nums.end(),0);
    //     if(total & 1) return false;    // if total sum is odd return false
    //     int target = total/2;
    //     vector<vector<int>>dp(n+1, vector<int>(target+1,-1));
    //     return fun(n-1,target,nums,dp); 
    // }
    int fun(int index, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return 1;
        if(index == 0) {
            if(nums[index] == target) return 1;
            return 0;
        }
        if(dp[index][target] != -1) return dp[index][target];
        int not_picked = fun(index-1,target,nums,dp);
        int picked = 0;
        if(target > nums[index]) picked = fun(index-1, target-nums[index], nums,dp);
        return dp[index][target] = not_picked||picked;
     }

};