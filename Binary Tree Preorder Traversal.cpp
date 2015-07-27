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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> st;
        if(root != NULL)
           st.push(root);
        while(!st.empty())
        {
            TreeNode *p = st.top();
            st.pop();
            ans.push_back(p->val);
            if(p->right != NULL)
                st.push(p->right);
            if(p->left != NULL)
                st.push(p->left);
        }
        return ans;
    }
};