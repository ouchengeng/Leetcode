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
ListNode *partition(ListNode *head, int x) 
{
	if(head == NULL||head->next == NULL)
		return head;
	ListNode *r1 = new ListNode(1);
	ListNode *r2 = new ListNode(1);
	ListNode *rr1 = r1, *rr2 = r2;
	while(head != NULL)
	{
	    ListNode *tmp = head->next;
		if(head->val < x)
		{
			rr1->next = head;
			rr1 = rr1->next;
			rr1->next = NULL;
		}
		else
		{
			rr2->next = head;
			rr2 = rr2->next;
			rr2->next = NULL;
		}
		head = tmp;
	}
	if(rr1 != r1)
	{
	    rr1->next = r2->next;
	    return r1->next;
	}
	else
	    return r2->next; 
}
};