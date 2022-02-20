class Solution {
public:
     void permutation(vector<int> nums, vector<int> &ds, set<vector<int>>                               &ans,bool vis[]){     //with using extra space
        if(ds.size()==nums.size()){
            // sort(ds.begin(),ds.end());
            ans.insert(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                ds.push_back(nums[i]);
                vis[i]=true;
                permutation(nums,ds,ans,vis);
                ds.pop_back();
                vis[i]=false;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         bool vis[nums.size()];
        memset(vis,false,sizeof(vis));
        set<vector<int>> ans;
        vector<int> ds;
        permutation(nums,ds,ans,vis);
        vector<vector<int>> res;
        for(auto it: ans)
            res.push_back(it);
        return res;
    }
};