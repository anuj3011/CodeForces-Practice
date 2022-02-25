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
    void findInorder(TreeNode* root, vector<int> &inorder){
        if(!root)
            return;
        findInorder(root->left,inorder);
        inorder.push_back(root->val);
        findInorder(root->right,inorder);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        findInorder(root,inorder);
        vector<int> temp=inorder;
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            if(temp[i]!=inorder[i] || (i>=1 && temp[i]==temp[i-1]))
                return false;
        }
        return true;
    }
};