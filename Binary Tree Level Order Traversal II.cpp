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
vector<vector<int> > levelOrderBottom(TreeNode *root) 
{
	vector<vector<int> > ans;
	if(root == NULL)
		return ans;
	vector<int> tmp(1, root->val);
	ans.push_back(tmp);
	queue<TreeNode *> value;
	queue<int> layer;
	int lay = 1;
	if(root->left != NULL)
	{
		value.push(root->left);
		layer.push(lay);
	}
	if(root->right != NULL)
	{
		value.push(root->right);
		layer.push(lay);
	}
	while(value.size() > 0)
	{
		lay++;
		int cur = layer.front();
		vector<int> tmp;
		while(layer.front() == cur)
		{
			TreeNode *r = value.front();
			value.pop();
			layer.pop();
			tmp.push_back(r->val);
			if(r->left != NULL)
			{
				value.push(r->left);
				layer.push(lay);
			}
			if(r->right != NULL)
			{
				value.push(r->right);
				layer.push(lay);
			}
		}
		ans.push_back(tmp);
	}
	for(int i = 0, j = ans.size() - 1; i < j; i++, j--)
	{
	    vector<int> tmp = ans[i];
	    ans[i] = ans[j];
	    ans[j] = tmp;
	}
	return ans;

}
};