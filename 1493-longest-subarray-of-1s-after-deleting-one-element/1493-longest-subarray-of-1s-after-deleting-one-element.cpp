class Solution {
public:
   /* int longestSubarray(vector<int>& nums) {      //works in O(n) but difficult to understand code
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
        
    }*/
    int longestSubarray(vector<int>&nums){
        int i=0,j=0,len=0,count=0;
        while(j<nums.size()){
            if(nums[j]==0)
                count++;
            if(count<=1){
                len=max(len,j-i);  //not j-i+1 because have to tell the length after deleting 0
                j++;
            }else{
                while(count>1){
                    if(nums[i]==0) count--;
                    i++;
                }
                j++;
            }
        }
        return len;
    }
};