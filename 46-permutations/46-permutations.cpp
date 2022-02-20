class Solution {//commented part is using extra space
public:
    // void permutation(vector<int> nums, vector<int> &ds, vector<vector<int>>                               &ans,bool vis[]){     //with using extra space
    //     if(ds.size()==nums.size()){
    //         ans.push_back(ds);
    //         return;
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         if(!vis[i]){
    //             ds.push_back(nums[i]);
    //             vis[i]=true;
    //             permutation(nums,ds,ans,vis);
    //             ds.pop_back();
    //             vis[i]=false;
    //         }
    //     }
    // }
    void permutations(vector<int> &nums, vector<vector<int>> &ans, int index){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            permutations(nums,ans,index+1);
            swap(nums[index],nums[i]);
            
        }        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        // bool vis[nums.size()];
        // memset(vis,false,sizeof(vis));
        vector<vector<int>> ans;
        vector<int> ds;
        // permutation(nums,ds,ans,vis);
        permutations(nums,ans,0);
        return ans;
    }
};