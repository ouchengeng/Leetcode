/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        if(p == NULL)
            return q;
        if(p->val == q->val)
            return p;
        int a = (p->val > q->val) ? q->val : p->val;
        int b = (p->val < q->val) ? q->val : p->val;
        while(root != NULL)
        {
            if(root->val < a && root->val < b)
                root = root->right;
            else if(root->val > a && root->val > b)
                root = root->left;
            else
                return root;
        }
        return root;
    }
};