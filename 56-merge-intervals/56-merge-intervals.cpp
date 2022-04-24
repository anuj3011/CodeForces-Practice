class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0)
            return ans;
        sort(intervals.begin(),intervals.end());
        vector<int> currIntervals=intervals[0];
        for(auto it: intervals){
            if(it[0]<=currIntervals[1]){
                currIntervals[1]=max(currIntervals[1],it[1]);
            }else{
                ans.push_back(currIntervals);
                currIntervals=it;
            }
        }
        ans.push_back(currIntervals);
        return ans;
    }
};