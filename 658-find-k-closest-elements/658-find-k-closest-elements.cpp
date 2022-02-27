typedef pair<int,int> pi;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pi,vector<pi>,greater<pi>> minH;
        for(int i=0;i<arr.size();i++){
            minH.push({abs(x-arr[i]),arr[i]});
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            auto temp=minH.top();
            minH.pop();
            ans.push_back(temp.second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};