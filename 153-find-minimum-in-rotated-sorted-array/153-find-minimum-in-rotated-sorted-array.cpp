class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int n=nums.size();
        while(low<=high){
            if(nums[low]<=nums[high]){
                cout<<low<<" "<<high;
                return nums[low];
            }
            int mid=low+ (high-low)/2;
            int next=(mid+1)%n;
            int prev=(mid-1+n)%n;
            if(nums[mid]<=nums[next] && nums[mid]<=nums[prev]){
                cout<<low<<" "<<high<<" "<<mid;
                return nums[mid];
            }
            else if(nums[mid]<=nums[high])
                high=mid-1;
            else
                low=mid+1;
        }
        return -1;
    }
};