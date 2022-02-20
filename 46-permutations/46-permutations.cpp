class Solution {
public:
    void permutation(vector<int> nums, vector<int> &ds, vector<vector<int>>                               &ans,bool vis[]){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
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
    
    vector<vector<int>> permute(vector<int>& nums) {
        bool vis[nums.size()];
        memset(vis,false,sizeof(vis));
        vector<vector<int>> ans;
        vector<int> ds;
        permutation(nums,ds,ans,vis);
        return ans;
    }
};