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
TreeNode *dfs(int in_left, int in_right, int post_left, int post_right, vector<int> &in, vector<int> &post)
{
    if(in_left > in_right || post_left > post_right)
		return NULL;
	TreeNode *root = new TreeNode(post[post_right]);
	if(in_left == in_right)
		return root;
	else
	{
		int i = m[post[post_right]];
		int left_size = i - in_left;
		root->left = dfs(in_left, i - 1, post_left, post_left + left_size - 1, in, post);
		root->right = dfs(i + 1, in_right, post_left + left_size, post_right - 1, in, post);
		return root; 
	}
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder){
	if(inorder.size() == 0 || postorder.size() == 0)
		return NULL;
	for(int i = 0; i < inorder.size(); i++)
	    m[inorder[i]] = i;
	return dfs(0, inorder.size() - 1, 0, inorder.size()- 1, inorder, postorder);
}
};