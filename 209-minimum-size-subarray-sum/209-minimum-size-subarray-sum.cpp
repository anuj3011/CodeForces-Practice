class Solution {
public:
   int minSubArrayLen(int k, vector<int>& nums) {
           int size=INT_MAX;
        int i=0,j=0;
        int sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum<k){
                j++;
            }
            // else if(sum==k)
            // {
            //     cout<<"if"<<i<<" "<<j<<endl;
            //     size=min(j-i+1,size);
            //     j++;
            // }
            else{
                //  size=min(j-i+1,size);
                // cout<<"else"<<i<<" "<<j<<endl;
                while(sum>=k){
                   size=min(j-i+1,size);
                    if(nums[i]>0)
                        sum-=nums[i];
                    else
                        sum+=nums[i];
                    i++;
                }
                cout<<"else"<<i<<" "<<j<<endl;
                // if(i==j)
                //     size=1;
                // else
                // cout<<j-i+1;
                //     size=min(j-i+2,size);
                j++;
            }
        }
        return (size==INT_MAX)?0:size;
   }
};