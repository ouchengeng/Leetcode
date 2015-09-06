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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return NULL;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *cur = newHead, *pre = newHead, *tmp;
        for(int i = 0; i < n; i++)
            cur = cur->next;
        while(cur != NULL)
        {
            tmp = pre;
            pre = pre->next;
            cur = cur->next;
        }
        tmp->next = pre->next;
        return newHead->next;
        
    }
};