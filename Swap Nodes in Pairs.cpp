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
    ListNode* swapPairs(ListNode* head)
    {
    	if(head == NULL || head->next == NULL)
    		return head;
    	ListNode *newHead = new ListNode(-1);
    	newHead->next = head;
    	ListNode *pre = newHead, *cur = head, *next = head->next;
    	while(next != NULL)
    	{
    		cur->next = next->next;
    		next->next = cur;
    		pre->next = next;
    		if(cur->next == NULL || cur->next->next == NULL)
    			break;
    		cur = cur->next;
    		next = cur->next;
    		pre = pre->next->next;
    	}
    	return newHead->next;
    }
};