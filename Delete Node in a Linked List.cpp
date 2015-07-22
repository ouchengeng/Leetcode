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
    void deleteNode(ListNode* node) {
        if(node == NULL)
            return;
        ListNode *pre = node, *next = node->next;
        while(next->next != NULL)
        {
            pre->val = next->val;
            pre = next;
            next = next->next;
        }
        pre->val = next->val;
        pre->next = NULL;
        delete next;
    }
};