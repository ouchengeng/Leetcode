/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode *deleteDuplicates(ListNode *head) 
{
	if(head == NULL || head->next == NULL)
		return head;
	ListNode *root = new ListNode(INT_MAX);
	ListNode *pre = root, *cur = head;
	while(cur != NULL)
	{
		int val;
		if(cur->next != NULL && cur->val == cur->next->val)
		{
			val = cur->val;
			while(cur != NULL && cur->val == val)
			{
			    ListNode *t = cur;
				cur = cur->next;
				delete t;
			}
			continue;
		}

		ListNode *tmp = cur;
		if(cur != NULL) 
			cur = cur->next;
		pre->next = tmp;
		pre = pre->next;
		pre->next = NULL;
	}
	return root->next;
}
};