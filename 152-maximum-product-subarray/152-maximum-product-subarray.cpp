class Solution {
public:
   
    int maxProduct(vector<int>& nums) {
        int currMax=nums[0];
        int currMin=nums[0];
        int res=currMax;
        for(int i=1;i<nums.size();i++){
            int temp=currMax;
             //1.nums[i] is the largest
            //2.currMax*nums[i] is the largest
            //3.minProduct*nums[i] is the largest, when nums[i] < 0
            currMax= max(nums[i],max(currMax*nums[i],currMin*nums[i]));
            currMin= min(nums[i],min(temp*nums[i],currMin*nums[i]));
            res=max(currMax,res);
        }
        return res;
    }
};