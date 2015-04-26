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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
    	if(l1 == NULL)
    		return l2;
    	else if(l2 == NULL)
    		return l1;
    	ListNode *head1 = new ListNode(-1);
    	ListNode *head = head1;
    	while(l1 != NULL && l2 != NULL)
    	{
    		ListNode *tmp;
    		if(l1->val < l2->val)
    		{
    			tmp = l1;
    			l1 = l1->next;
    		}
    		else
    		{
    			tmp = l2;
    			l2 = l2->next;
    		}
    		head->next = tmp;
    		head = head->next;
    		tmp->next = NULL;
    	}
    	if(l1 != NULL)
    	    head->next = l1;
    	else if(l2 != NULL)
    	    head->next = l2;
    	return head1->next;
    }
};