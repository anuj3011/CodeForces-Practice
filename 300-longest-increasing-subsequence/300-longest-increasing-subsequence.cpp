class Solution {
public:
    int f(int ind, int prevInd, vector<int> &nums, vector<vector<int>> &dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][prevInd+1]!=-1) return dp[ind][prevInd+1];
        int pick=0;
        int notPick= f(ind+1,prevInd,nums,dp);
        if(prevInd==-1 || nums[prevInd]<nums[ind])
            pick= 1 + f(ind+1,ind,nums,dp);
        return dp[ind][prevInd+1]=max(pick,notPick);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // int n=nums.size();
        // vector<vector<int>> dp(n,vector<int> (n+1,-1));
        // return f(0,-1,nums,dp);
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(temp.back()<nums[i]){
                temp.push_back(nums[i]);
            }else{
                int ind= lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return temp.size();
    }
};