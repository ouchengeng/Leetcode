class Solution {
public:
	int countNodes(TreeNode* root) {
	if(root == NULL)
		return 0;
	int left = 0, right = 0;
	TreeNode *p = root;
	for(p = root; p != NULL; p = p->left)
   		left++;
    for(p = root; p != NULL; p = p->right)
		right++;
	if(left == right)
	    return  (1 << left) - 1;
	else 
	    return countNodes(root->left) + countNodes(root->right) + 1;
	}
};