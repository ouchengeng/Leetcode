/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
 

TreeNode *recurse(ListNode *root)
{
	if(root == NULL)
		return NULL;
	if(root->next == NULL)
	{
		TreeNode *t = new TreeNode(root->val);
		return t;
	}
	else if(root->next->next == NULL)
	{
		TreeNode *t1 = new TreeNode(root->val);
		TreeNode *t2 = new TreeNode(root->next->val);
		t1->right = t2;
		return t1;
	}
	ListNode *slow = root, *fast = root->next, *pre = slow;
	while(fast != NULL && fast->next != NULL)
	{
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	if(fast != NULL)
	{
		pre = slow;
		slow = slow->next;
	}
	pre->next = NULL;
	TreeNode *t = new TreeNode(slow->val);
	t->left = recurse(root);
	t->right = recurse(slow->next);
	return t;
}
TreeNode *sortedListToBST(ListNode *head)
{
	if(head == NULL)
		return NULL;
	return recurse(head);
}
};