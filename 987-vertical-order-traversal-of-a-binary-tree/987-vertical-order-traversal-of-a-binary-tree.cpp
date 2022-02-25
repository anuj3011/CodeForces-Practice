/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        map<int,vector<int>> mp;
        vector<vector<int>> ans;
        while(!q.empty()){
            vector<pair<int,int>>a;
            int n=q.size();
            while(n--){
                pair<TreeNode*,int> p=q.front();
                q.pop();
                a.push_back({p.first->val,p.second});
                TreeNode* temp=p.first;
                int hd=p.second;
                // mp[hd].push_back(temp->val);
                if(temp->left) q.push({temp->left,hd-1});
                if(temp->right) q.push({temp->right,hd+1});
            }  
            sort(a.begin(),a.end());
            for(int i=0;i<a.size();i++)
                mp[a[i].second].push_back(a[i].first);
        }
        
        for(auto it:mp){
            // sort(it.second.begin(),it.second.end());
            ans.push_back(it.second);
        }
        // sort(ans.begin(),ans.end());
        return ans;
    }
};