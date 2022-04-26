class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            vector<int> temp;
            temp.push_back(nums[i]);
            for(int j=i+1;j<n-2;j++){
                temp.push_back(nums[j]);
                int low=j+1,high=n-1;
                int rem=target-nums[i]-nums[j];
                while(low<high){
                    if(nums[low]+nums[high]==rem){
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        temp.pop_back();
                        temp.pop_back();
                        cout<<i<<" "<<j<<" "<<low<<" "<<high<<endl;
                        if(nums[low]==nums[low+1]) 
                            while(low<n-1 && nums[low]==nums[low+1]) low++;
                        if(nums[high]==nums[high-1])
                            while(high>0 && nums[high]==nums[high-1]) high--;
                        low++;
                        high--;
                        // cout<<"after:"<<i<<" "<<j<<" "<<low<<" "<<high<<endl;
                        // break;
                        // low++;
                        // high--;
                    }
                    else if(nums[low]+nums[high]<rem){
                        if(nums[low]==nums[low+1]) 
                            while(low<n-1 && nums[low]==nums[low+1]) low++;
                        else 
                            low++;
                    }else{
                        if(nums[high]==nums[high-1])
                            while(high>0 && nums[high]==nums[high-1]) high--;
                        else 
                            high--;
                    }
                }
                temp.pop_back();
                while(j<n-2 && nums[j]==nums[j+1]) j++;
            }
            while(i<n-3 && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};