class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int n = A.size(), m = B.size(), start, end;
        
        for (int i=0, j=0; i<n && j<m; A[i][1] <= B[j][1] ? ++i : ++j){
            start = max(A[i][0], B[j][0]);
            end = min(A[i][1], B[j][1]);
            
            if (start <= end)
                ans.push_back({start, end});
        }
        
        return ans;
    }
};