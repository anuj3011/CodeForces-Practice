class Solution {
public:
   
    // int  f(vector<int> &nums,int ind,vector<int> &dp){ //memoitation
    //     if(ind==0) return nums[ind];
    //     if(ind<0) return 0;
    //     if(dp[ind]!=-1)
    //         return dp[ind];
    //     int pick=f(nums,ind-2,dp)+nums[ind];
    //     int notPick=0+f(nums,ind-1,dp);
    //     return dp[ind]=max(pick,notPick);
    // }
//     int rob(vector<int>& nums) { //tabulation
//         int ind=nums.size()-1;
//         int n=nums.size();
//         // vector<int> dp(ind+1,-1);
//         // f(nums,ind,dp);
//         // return dp[ind];
        
//         vector<int> dp(n,-1);
//         dp[0]=nums[0];
//         // dp[1]=nums[1];
//         for(int i=1;i<n;i++){
//             int pick = nums[i];
//             if(i>1) pick+= dp[i-2];
//             int notPick= dp[i-1];
//             dp[i]=max(pick,notPick);
//         }
//         return dp[n-1];
//     }
    int rob(vector<int> &nums){
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notPick=prev;
            int curr=max(pick,notPick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    
};