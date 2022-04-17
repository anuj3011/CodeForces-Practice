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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> inO;
        inorder(root,inO);
        TreeNode* ans=new TreeNode(0);
        TreeNode* cur=ans;
        for(auto it: inO){
            cur->right= new TreeNode(it);
            cur=cur->right;
        }
        return ans->right;   
    }
    void inorder(TreeNode* root, vector<int> &inO){
        if(!root) return;
        inorder(root->left,inO);
        inO.push_back(root->val);
        inorder(root->right,inO);
    }
};