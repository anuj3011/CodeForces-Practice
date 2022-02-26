class Solution {
public:
    bool isValid(vector<int> nums, int mid,int threshold){
        int count=0;
        // cout<<mid<<endl;
        for(int i=0;i<nums.size();i++){
            // cout<<count<<" "<<nums[i];
            double temp=(double)nums[i]/mid;
            count+=ceil(temp);
            // cout<<" "<<count<<endl;
            if(count>threshold)
                return false;
        }
        return true;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
       int mx=INT_MIN;
        for(int i=0;i<nums.size();i++)
            mx=max(mx,nums[i]);
        int i=1,j=mx,res=0;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(isValid(nums,mid,threshold)){
                res=mid;
                j=mid-1;
            }else
                i=mid+1;
            // cout<<mid<<" "<<i<<" "<<j<<endl;
        }
       return res;
    }
};