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

struct cmp
{
    bool operator() ( ListNode* i, ListNode* j)
        {
        return i->val > j->val;
        }
};
ListNode *mergeKLists(vector<ListNode *> &lists) 
{
    if(lists.size() == 0)
    	return NULL;
    if(lists.size() == 1)
        return lists[0];
    priority_queue<ListNode *, vector<ListNode *>, cmp> q;
    int n = lists.size();
    for(int i = 0; i < n; i++)
        if(lists[i] != NULL)
    	    q.push(lists[i]);

    ListNode *head = new ListNode(-1);
    ListNode *p = head;
    while(q.size() > 0)
    {
    	ListNode *tmp = q.top();
    	q.pop();
    	head->next = tmp;
    	if(tmp->next != NULL)
    		q.push(tmp->next);
    	tmp->next = NULL;
    	head = head->next;
    }
    head = p;
    p = p->next;
    free(head);
    return p;

}
};