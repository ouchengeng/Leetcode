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
unordered_map<int, int> m;

TreeNode *dfs(int pre_left, int pre_right, int in_left, int in_right, vector<int> &pre, vector<int> &in)
{
	if(pre_left > pre_right || in_left > in_right)
		return NULL;
	TreeNode *root = new TreeNode(pre[pre_left]);
	if(pre_left == pre_right)
		return root;
	int split = m[pre[pre_left]];
	int size = split - in_left;
	root->left = dfs(pre_left + 1, pre_left + size, in_left, in_left + size - 1, pre, in);
	root->right = dfs(pre_left + size + 1, pre_right, split + 1, in_right, pre, in);
	return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) 
{
	if(preorder.size() == 0 || preorder.size() != inorder.size())
		return NULL;
	for(int i = 0; i < inorder.size(); i++)
		m[inorder[i]] = i;
	return dfs(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);

}
};