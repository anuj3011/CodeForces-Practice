class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       
        int left=0,right=nums.size()-1,index=nums.size()-1;
        vector<int> res(nums.size());
        for(int i=0;i<nums.size();i++){
            nums[i]*=nums[i];
        }
        while(left<=right){
            if(nums[left]>nums[right]){
                res[index--]=nums[left++];
            }else{
                res[index--]=nums[right--];
            }
        }
        return res;
    }
};