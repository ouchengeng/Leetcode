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
    ListNode * reverse(ListNode *head, int offset)
    {
    	ListNode *pre = head, *cur = head->next, *next = head;
    	head->next = NULL;
    	for(int i = 1; i < offset; i++)
    	{
    		next = cur->next;
    		cur->next = pre;
    		pre = cur;
    		cur = next;
    	}
    	head->next = cur->next;
    	cur->next = pre;
    	return cur;
    }
    ListNode *reverseBetween(ListNode *head, int m, int n) 
    {
    	if(m == n)
    		return head;
    	ListNode *root = new ListNode(-1);
    	root->next = head;
    	ListNode *pre = root, *cur = root;
    	for(int i = 0; i < m; i++)
    	{
    		pre = cur;
    		cur = cur->next;
    	}
    	cur = reverse(cur, n - m);
    	pre->next = cur;
    	cur = root->next;
    	delete root;
    	return cur;
    }
};