typedef pair<int,int> pii;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        priority_queue<pii,vector<pii>,greater<pii>> minh;
        for(auto it: mp){
            minh.push({it.second,it.first});
            if(minh.size()>k)
                minh.pop();
        }
        vector<int> ans;
        while(!minh.empty()){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};