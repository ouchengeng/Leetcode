/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode *root, long min, long max)
    {
    	if(root == NULL)
    		return true;
    	if(!(root->val > min && root->val < max))
    		return false;
    	return dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
    }
    bool isValidBST(TreeNode *root)
    {
    	if(root == NULL)
    		return true;
    	return dfs(root->left, LONG_MIN, root->val) && dfs(root->right, root->val, LONG_MAX);
    }
};