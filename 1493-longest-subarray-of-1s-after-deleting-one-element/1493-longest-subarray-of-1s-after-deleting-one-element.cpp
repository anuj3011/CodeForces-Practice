class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0;
        int len=0,flag=1;
        while(j<nums.size()){
            if(!nums[j]){
                if(flag==0){
                    while(nums[i]){
                        i++;
                    }
                    i++;
                    len=max(len,j-i-1);
                    cout<<i<<" "<<j<<" "<<len<<" "<<flag<<endl;
                    j++;
                }else{
                    len=max(len,j-i);
                    flag=0;
                    j++;
                }
            }else{
                len=max(len,j-i);cout<<i<<" "<<j<<" "<<len<<" "<<flag<<endl;
                j++;
            }
        }
        return len;
        
    }
};