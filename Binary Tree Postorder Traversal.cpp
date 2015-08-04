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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        if(root != NULL)
            s.push(root);
        TreeNode *cur = root, *pre = NULL;
        vector<int> vec;
        while(!s.empty())
        {
            cur = s.top();
            if((cur->left == NULL && cur->right == NULL) || ((pre != NULL) && (cur->left == pre || cur->right == pre)))
            {
                vec.push_back(cur->val);
                s.pop();
                pre = cur;
            }
            else
            {
                if(cur->right != NULL)
                    s.push(cur->right);
                if(cur->left != NULL)
                    s.push(cur->left);
            }
        }
        return vec;
    }
};