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
    ListNode *rotateRight(ListNode *head, int k) {
    	if(head == NULL)
    		return head;
    	ListNode *next = head, *pre = head;
    	int count = 0;
    	while(next != NULL)
    	{
    		count++;
    		next = next->next;
    	}
    	k = k % count;
    	next = head;
    	for(int i = 0; i < k; i++)
    		next = next->next;
    	while(next->next != NULL)
    	{
    		next = next->next;
    		pre = pre->next;
    	}
    	next->next = head;
    	next = pre->next;
    	pre->next = NULL;
    	return next;
    }
};