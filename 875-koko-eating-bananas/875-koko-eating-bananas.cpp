class Solution {
public:
    
     bool isValid(vector<int> nums, int mx, int m){
        int count=0;
        cout<<mx<<endl;
         int n=nums.size();
        for(int i=0;i<n;i++){
            count+=ceil((nums[i]*1.0)/mx);
            // if(sum>mx){
            //     count++;
            //     sum=nums[i];
            // }
            if(count>m){
                return false;
            }
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& nums, int m) {
        int sum=0,res=-1,mx=-1;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
            // sum+=nums[i];
        }
        int start=1,end=mx;
        while(start<=end){
            int mid= start+ (end-start)/2;
            if(isValid(nums,mid,m)){
                end=mid-1;
                res=mid;
            }else
                start=mid+1;
        }
        return res;
    }
};