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
    bool dfs(TreeNode* root, TreeNode* p,  vector<TreeNode*> &vec)
    {
        if(root == NULL || p == NULL)
            return false;
        vec.push_back(root);
        if(root == p)
            return true;
        if(dfs(root->left, p, vec))
            return true;
        if(dfs(root->right, p, vec))
            return true;
        vec.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        if(p == NULL)
            return q;
        vector<TreeNode*> p1, p2;
        dfs(root, p, p1);
        dfs(root, q, p2);
        int size = min(p1.size(), p2.size()) - 1;
        for(int i = size; i >= 0; i--)
            for(int j = size; j >= 0; j--)
                if(p1[i] == p2[j])
                    return p1[i];
        return NULL;
    }
};