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
    void inorder(TreeNode* root, vector<int> &ans){
        if(!root) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    void inorder2(TreeNode* root, vector<int> &ans, int &i){
        if(!root) return;
        inorder2(root->left,ans,i);
        root->val=ans[i++];
        inorder2(root->right,ans,i);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> inO;
        inorder(root,inO);
        sort(inO.begin(),inO.end());
        int i=0;
        inorder2(root,inO,i);
    }
};