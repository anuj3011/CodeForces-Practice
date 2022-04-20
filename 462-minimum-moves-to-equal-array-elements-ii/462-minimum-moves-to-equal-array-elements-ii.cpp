class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int res=0;
        for(auto it: nums){
            res+= abs(it-nums[n/2]);
        }
        return res;
    }
};