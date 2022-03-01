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
    void findSum(TreeNode* root,int curr_sum,int targetSum,bool &found){
        if(!root) return;
        curr_sum+=root->val;
        if(!root->left && !root->right && curr_sum==targetSum){
            found=true;
        }
        findSum(root->left,curr_sum,targetSum,found);
        findSum(root->right,curr_sum,targetSum,found);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        int curr_sum=0;
        bool found=false;
        findSum(root,curr_sum,targetSum,found);
        return found;
    }
};