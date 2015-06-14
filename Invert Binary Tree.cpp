/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = right;
        root->right = left;
        invertTree(left);
        invertTree(right);
        return root;
    }
};