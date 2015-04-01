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
TreeNode *clone(TreeNode *root)
{
	if(root == NULL)
		return NULL;
	TreeNode *t = new TreeNode(root->val);
	t->left = clone(root->left);
	t->right = clone(root->right);
	return t;
}
vector<TreeNode *> dfs(int l, int r)
{
	vector<TreeNode *> ans;
	if(l == r)
	{
		TreeNode *t = new TreeNode(l);
		ans.push_back(t);
		return ans;
	}
	else if(l > r)
	{
		ans.push_back(NULL);
		return ans;
	}
	for(int i = l; i <= r; i++)
	{
		vector<TreeNode *> left = dfs(l, i - 1);
		vector<TreeNode *> right = dfs(i + 1, r);
		int times_r = right.size(), pos_r = left.size();
		int times_l = left.size(), pos_l = right.size();
		
		left.resize(times_r * pos_r);
		int starter = pos_r;
		for(int k = 0; k < times_r - 1; k++)
			for(int j = 0; j < pos_r; j++)
				left[starter++] = clone(left[j]);
		
		right.resize(times_l * pos_l);
		int last = right.size() - 1;
		for(int k = pos_l - 1; k >= 0; k--)
		{
			right[last--] = right[k];
			for(int j = 0; j < times_l - 1; j++)
				right[last--] = clone(right[k]);
		}
		for(int j = 0; j < left.size(); j++)
		{
			TreeNode *t = new TreeNode(i);
			t->left = left[j];
			t->right = right[j];
			ans.push_back(t);
		}
	}
	return ans;
}
vector<TreeNode *> generateTrees(int n)
{
	vector<TreeNode *> ans;
	return dfs(1, n);
}
};