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
    int ans, nums, k;
    bool visit(TreeNode *root)
    {
    	nums++;
    	if(nums == k)
    	{
    		ans = root->val;
    		return true;
    	}
    	return false;
    }
    bool dfs(TreeNode *root)
    {
    	if(root == NULL)
    		return false;
    	if(dfs(root->left))
    		return true;
    	if(visit(root))
    		return true;
    	if(dfs(root->right))
    		return true;
    	return false;
    }
    int kthSmallest(TreeNode* root, int kth) {
        nums = 0;
        k = kth;
        dfs(root);
        return ans;
    }
};