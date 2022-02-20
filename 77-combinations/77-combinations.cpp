class Solution {
public:
    void find(int index ,int n,int k,vector<int> &ds,vector<vector<int>> &ans){
        if(k==0){
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<=n;i++){
            ds.push_back(i);
            find(i+1,n,k-1,ds,ans);
            ds.pop_back();
            
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> ds;
        vector<vector<int>> ans;
        find(1,n,k,ds,ans);
        return ans;
    }
};