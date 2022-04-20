class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn= *min_element(nums.begin(),nums.end());
        int res=0;
        for(int it: nums){
            res+= it-mn;
        }
        return res;
    }
};