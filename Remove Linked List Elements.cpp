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
    ListNode* removeElements(ListNode* head, int val)
    {
    	if(head == NULL)
    		return head;
    	ListNode *newHead = new ListNode(-1);
    	newHead->next = head;
    	ListNode *pre = newHead, *cur = head;
    	while(cur != NULL)
    	{
    		if(cur->val == val)
    		{
    			ListNode *tmp = cur;
    			cur = cur->next;
    			pre->next = cur;
    			delete tmp;
    		}
    		else
    		{
    			pre = pre->next;
    			cur = cur->next;
    		}
    	}
    	return newHead->next;
    }
};