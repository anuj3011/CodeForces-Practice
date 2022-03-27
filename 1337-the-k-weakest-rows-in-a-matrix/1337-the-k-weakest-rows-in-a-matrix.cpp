class Solution {
public:
    int countBS(vector<int> arr){
        int low=0,high=arr.size()-1;
        int res=-1;
        while(low<=high){
            int mid=low + (high-low)/2 ;
            if(arr[mid]==1){
                res=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return res;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(int i=0;i<mat.size();i++){
            int cnt=countBS(mat[i]);
            pq.push({cnt,i});
            if(pq.size()>k)
                pq.pop();
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};