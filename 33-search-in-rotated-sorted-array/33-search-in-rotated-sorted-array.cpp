class Solution {
public:
    int binarySearch(vector<int> nums,int start,int end,int target){
        cout<<start<<" "<<end<<endl;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        int n=nums.size();
        int minIndex=-1;
        while(low<=high){
            if(nums[low]<=nums[high]){
                minIndex=low;
                break;
            }
            int mid=low+ (high-low)/2;
            int next=(mid+1)%n;
            int prev=(mid-1+n)%n;
            if(nums[mid]<=nums[next] && nums[mid]<=nums[prev]){
                minIndex=mid;
                break;
            }
            else if(nums[mid]<=nums[high])
                high=mid-1;
            else
                low=mid+1;
        }
        int ind1= binarySearch(nums,0,minIndex-1,target);
        int ind2= binarySearch(nums,minIndex,n-1,target);
        
        return (ind1==-1)?ind2:ind1;
    }
};