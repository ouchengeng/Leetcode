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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        ListNode *pre = head;
        int flag = 0;
        while(l1 != NULL || l2 != NULL)
        {
            int v1 = 0, v2 = 0;
            if(l1 != NULL)
            {
                v1 = l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                v2 = l2->val;
                l2 = l2->next;
            }
            int v = (v1+v2+flag) % 10;
            flag = (v1+v2+flag) / 10;
            ListNode *cur = new ListNode(v);
            pre->next = cur;
            pre = cur;
        }
        if(flag)
        {
            ListNode *cur = new ListNode(flag);
            pre->next = cur;
        }
        return head->next;
    }
};