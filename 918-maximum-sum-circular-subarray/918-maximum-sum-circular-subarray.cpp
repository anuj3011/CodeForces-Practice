class Solution {
public:
    
    int maxSum(vector<int> &nums){
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(maxi<sum) maxi=sum;
            if(sum<0) sum=0;
        }
        return maxi;
    }
    
    int minSum(vector<int> &nums){
        int sum=0;
        int minS=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(minS>sum) minS=sum;
            if(sum>0) sum=0;
        }
        return minS;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxS=maxSum(nums);
        int minS=minSum(nums);
        int totSum=0;
        for(auto it: nums) totSum+=it;
        if(maxS>0)
            return max(maxS,totSum-minS);
        return maxS;
    }
};