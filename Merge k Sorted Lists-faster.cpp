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
std::vector<ListNode *> root;
ListNode *mergeTwoLists(ListNode *t1, ListNode *t2)
{
    ListNode *head = new ListNode(-1);
    ListNode *p = head;
    while(t1 != NULL && t2 != NULL)
    {
        if(t1->val < t2->val)
        {
            head->next = t1;
            t1 = t1->next;
            head->next->next = NULL;
        }
        else
        {
            head->next = t2;
            t2 = t2->next;
        }
        head->next->next = NULL;
        head = head->next;

    }
    if(t1 != NULL)
        head->next = t1;
    else
        head->next = t2;
    return p->next;
}
ListNode* divide(int head, int tail)
{
    ListNode *ans;
    if(head == tail)
        return root[head];
    else if(head == tail + 1)
    {
        ans = mergeTwoLists(root[head], root[tail]);
    }
    else
    {
        int mid = (tail + head) / 2;
        ListNode *p = divide(head, mid);
        ListNode *q = divide(mid + 1, tail);
        ans = mergeTwoLists(p, q);
    }
    return ans;
}
ListNode *mergeKLists(vector<ListNode *> &lists) 
{
    if(lists.size() == 0)
        return NULL;
    if(lists.size() == 1)
        return lists[0];
    root = lists;
    return divide(0, lists.size() - 1);
}
};