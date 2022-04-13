class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flag=false;
        int n=nums.size();
        if(nums[0]<=nums[n-1]) flag=true;
        
        if(flag){
            for(int i=0;i<n-1;i++){
                if(nums[i]>nums[i+1])
                    return false;
            }
        }
        else{
            for(int i=0;i<n-1;i++){
                if(nums[i]<nums[i+1])
                    return false;
            }
        }
        return true;
    }
};