class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // while (nums[0] != nums[nums[0]])
        //     swap(nums[0], nums[nums[0]]);
        // return nums[0];
        int slow=nums[0],fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};