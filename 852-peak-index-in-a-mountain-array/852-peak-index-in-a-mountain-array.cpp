class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
         int low=0,high=nums.size()-1;
        int n=nums.size();
        if(nums.size()==1)
            return 0;
        while(low<=high){
            int mid= low + (high-low)/2;
            if(mid>0 && mid<n-1){
                if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
                    return mid;
                if(nums[mid+1]>nums[mid-1])
                    low=mid+1;
                else 
                    high=mid-1;
            }else{
                if(mid==0){
                    if(nums[0]>nums[1])
                        return 0;
                    else return 1;
                }else{
                    if(nums[n-1]>nums[n-2])
                        return n-1;
                    else return n-1;
                }
            }
        }
        return -1;
    }
};