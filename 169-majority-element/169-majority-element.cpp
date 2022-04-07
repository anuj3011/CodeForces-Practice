class Solution {
public:
    // int majorityElement(vector<int>& nums) {
    //     unordered_map<int,int> mp;
    //     for(int i:nums)
    //         mp[i]++;
    //     for(auto it: mp){
    //         if(it.second> nums.size()/2)
    //             return it.first;
    //     }
    //     return 0;
    // }
    int majorityElement(vector<int>& nums){
        int count=0,element=0;
        for(auto it: nums){
            if(count==0) element=it;
            if(it==element) count++;
            else count--;
        }
        return element;
    }
};