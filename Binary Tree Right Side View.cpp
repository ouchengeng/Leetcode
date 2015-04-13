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
    vector<int> rightSideView(TreeNode *root)
    {
    	vector<int> ans;
    	if(root == NULL)
    		return ans;
    	queue<TreeNode *> q1;
    	queue<TreeNode *> q2;
    	q1.push(root);
    	int val;
    	while(q1.size() != 0)
    	{
    		TreeNode *t = q1.front();
    		q1.pop();
    		if(t->left != NULL)
    			q2.push(t->left);
    		if(t->right != NULL)
    			q2.push(t->right);
    		val = t->val;
    		if(q1.size() == 0)
    		{
    			ans.push_back(val);
    			queue<TreeNode *> tmp = q1;
    			q1 = q2;
    			q2 = tmp;
    		}
    	}
    	return ans;
    }
};