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
    int ans;
    int dfs(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int cur = root->val;
        if(left > 0)
            cur += left;
        if(right > 0)
            cur += right;
        if(cur > ans)
            ans = cur;
        return max(0, max(left, right)) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};