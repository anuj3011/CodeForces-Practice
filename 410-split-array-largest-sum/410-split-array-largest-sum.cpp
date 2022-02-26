class Solution {
public:
    bool isValid(vector<int> nums, int mx, int n, int m){
        int sum=0,count=1;
        cout<<mx<<endl;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>mx){
                count++;
                sum=nums[i];
            }
            if(count>m){
                return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int mx=INT_MIN,sum=0,res=-1;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
            sum+=nums[i];
        }
        int start=mx,end=sum;
        while(start<=end){
            int mid= start+ (end-start)/2;
            if(isValid(nums,mid,nums.size(),m)){
                end=mid-1;
                res=mid;
            }else
                start=mid+1;
        }
        return res;
    }
};