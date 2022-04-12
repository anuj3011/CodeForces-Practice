class Solution {
public:
   // int minSubArrayLen(int k, vector<int>& nums) {  //using sliding window
   //         int size=INT_MAX;
   //      int i=0,j=0;
   //      int sum=0;
   //      while(j<nums.size()){
   //          sum+=nums[j];
   //          if(sum<k){
   //              j++;
   //          }
   //          else{
   //              while(sum>=k){
   //                 size=min(j-i+1,size);
   //                  if(nums[i]>0)
   //                      sum-=nums[i];
   //                  else
   //                      sum+=nums[i];
   //                  i++;
   //              }
   //              cout<<"else"<<i<<" "<<j<<endl;
   //              j++;
   //          }
   //      }
   //      return (size==INT_MAX)?0:size;
   // }
    int minSubArrayLen(int target, vector<int>& nums) { 
        
        int low=1,high=nums.size();
        int res=0;
        while(low<=high){
            int mid= (low+high)/2;
            if(isPossible(nums,mid,target)){
                res=mid;
                high=mid-1;
            }else
                low=mid+1;
        }
        return res==0?0:res;
    }
    
    bool isPossible(vector<int> &nums, int size, int target){
        int low=0,sum=0,count=0;
        for(int i=0;i<nums.size();i++){
            if(count>=size){
                sum-=nums[low++];
                count--;
            }
            sum+=nums[i];
            count++;
            if(sum>=target)
                return true;
        }
        return false;
    }
    
};