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
	TreeNode *recursive(vector<int> &num, int left, int right)
	{
		if(left == right)
		{
			TreeNode *t = new TreeNode(num[left]);
			return t;
		}
		else if(left == right - 1)
		{
			TreeNode *t1 = new TreeNode(num[left]);
			TreeNode *t2 = new TreeNode(num[right]);
			t1->right = t2;
			return t1;
		}
		else
		{
			int mid = (left + right) / 2;
			TreeNode *t = new TreeNode(num[mid]);
			t->left = recursive(num, left, mid - 1);
			t->right = recursive(num, mid + 1, right);
			return t;
		}
	}
    TreeNode *sortedArrayToBST(vector<int> &num) {
    	if(num.size() == 0)
    		return NULL;
    	return recursive(num, 0, num.size() - 1);
    }
};