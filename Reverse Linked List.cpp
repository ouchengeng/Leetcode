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
    ListNode* reverseList(ListNode* head)
    {
    	if(head == NULL || head->next == NULL)
    		return head;
    	ListNode *pre = head, *cur = head->next;
    	pre->next = NULL;
    	while(cur != NULL)
    	{
    		ListNode *tmp = cur->next;
    		cur->next = pre;
    		pre = cur;
    		cur = tmp;
    	}
    	return pre;
    }
};