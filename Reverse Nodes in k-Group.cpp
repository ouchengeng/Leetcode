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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 1)
            return head;
        ListNode *dump = new ListNode(-1);
        dump->next = head;
        ListNode *previous = dump;
        ListNode *start = head, *end = head;
        while(true)
        {
            for(int i = 1; i < k && end; i++)
                end = end->next;
            if(!end)
                break;
            ListNode *next = end->next;
            ListNode *pre = start, *p = start->next;
            pre->next = next;
            for(int i = 1; i < k; i++)
            {
                end = p->next;
                p->next = pre;
                pre = p;
                p = end;
            }
            previous->next = pre;
            previous = start;
            end = start = next;
        }
        return dump->next;
    }
};