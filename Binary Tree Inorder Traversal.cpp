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
	void leftDown(TreeNode *root, stack<TreeNode*> &s)
	{
		while(root)
		{
			s.push(root);
			root = root->left;
		}
	}
    vector<int> inorderTraversal(TreeNode *root)
    {
    	vector<int> ans;
    	stack<TreeNode*> s;
    	leftDown(root, s);
    	while(!s.empty())
    	{
    		TreeNode *t = s.top();
    		s.pop();
    		ans.push_back(t->val);
    		leftDown(s->right, s);
    	}
    	return ans;
    }
};