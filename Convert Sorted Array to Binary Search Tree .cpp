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
    TreeNode* create(vector<int> &nums, int l, int r)
    {
        if(l > r)
            return NULL;
        int pos = (l+r)/2;
        TreeNode *root = new TreeNode(nums[pos]);
        root->left = create(nums, l, pos-1);
        root->right = create(nums, pos+1, r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create(nums, 0, nums.size()-1);
    }
};