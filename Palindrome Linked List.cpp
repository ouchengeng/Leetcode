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
    ListNode* reverse(ListNode *head){
        if(head->next == NULL)
            return head;
        ListNode *p = head, *q = head->next, *pre;
    	head->next = NULL;
        while(q != NULL)
        {
            pre = q->next;
            //p->next = NULL;
            q->next = p;
            p = q;
            q = pre;
        }
        return p;
    }
    ListNode* split(ListNode *head) {
        ListNode *fast, *slow, *pre;
        fast = slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast != NULL)
        {
            pre = slow;
            slow = slow->next;
        }
        pre->next = NULL;
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode *half = split(head);
        half = reverse(half);
        while(half != NULL)
        {
            if(head->val != half->val)
                return false;
            head = head->next;
            half = half->next;
        }
        return true;
    }
}; 