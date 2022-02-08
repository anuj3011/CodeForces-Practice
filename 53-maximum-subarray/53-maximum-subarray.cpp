class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sumSofar=INT_MIN;
        int max_ending_here=0;
        for(int i=0;i<nums.size();i++){
            max_ending_here+=nums[i];
            if(sumSofar<max_ending_here)
                    sumSofar=max_ending_here;
            if(max_ending_here<0)
                max_ending_here=0;
        }
        return sumSofar;
    }
};