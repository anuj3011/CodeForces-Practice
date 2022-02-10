class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int i=0,j=0;
        if(k>nums.size()){
            ans.push_back(*max_element(nums.begin(),nums.end()));
            return ans;
        }
        // vector<int> temp;
        list<int> temp;
        while(j<nums.size()){
            while(temp.size()>0 && temp.back()<nums[j]){
                temp.pop_back();
            }
            temp.push_back(nums[j]);
            if(j-i+1<k)
                j++;
            else if(j-i+1==k){
                ans.push_back(temp.front());
                if(temp.front()==nums[i]){
                    temp.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};