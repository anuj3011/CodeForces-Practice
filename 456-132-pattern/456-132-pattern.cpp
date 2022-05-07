class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int thirdEle=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<thirdEle) return true;
            while(st.size()>0 && st.top()<nums[i]){
                thirdEle=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};