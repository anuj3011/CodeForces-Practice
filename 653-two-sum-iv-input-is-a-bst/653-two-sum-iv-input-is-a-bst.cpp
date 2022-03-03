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
    bool searchnode(TreeNode* root, int val){
        if(root==NULL) return false;
        if(root->val == val) return true;
        return searchnode(root->left, val) || searchnode(root->right, val);
    }
    void inorder(TreeNode* root, vector<int>& ans){
         
         if(root==NULL) return ;
         inorder(root->left,ans);
         ans.push_back(root->val);
         inorder(root->right,ans);
        
     }
    
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> ans;
        inorder(root,ans);
        if(root==NULL || ans.size()<2 ) return false;
        for(int i=0; i<ans.size(); i++){
            if(searchnode(root, k - ans[i])== true && 2*ans[i]!=k)
                return true;
        }
        return false;
    }
};