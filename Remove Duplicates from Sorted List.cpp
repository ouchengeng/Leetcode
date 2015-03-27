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
	ListNode *pre = head;
	ListNode *cur = head->next;

	pre->next = NULL;
	while(cur != NULL)
	{
		if(cur->val == pre->val)
		{
		    ListNode *t = cur->next;
		    delete cur;
		    cur = t;
			continue;
		}
		ListNode *t = cur->next;
		pre->next = cur;
		pre = pre->next;
		pre->next = NULL;
		cur = t;
	}
    return head; 
}
};