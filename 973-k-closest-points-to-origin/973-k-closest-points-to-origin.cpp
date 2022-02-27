class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> maxh;
        for(int i=0;i<points.size();i++){
            double dist= points[i][0]*points[i][0] + points[i][1]*points[i][1];
            dist= sqrt(dist);
            maxh.push({dist,points[i]});
            if(maxh.size()>k)
                maxh.pop();
        }
        vector<vector<int>> ans;
        while(!maxh.empty()){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        return ans;
    }
};