struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root)
{
	if(root == NULL)
		return;
	queue<TreeLinkNode *> q;
	q.push(root);q.push(NULL);
	while(!q.empty())
	{
		TreeLinkNode *t = q.front();
		q.pop();
		while(t != NULL)
		{
			t->next = q.front();
			if(t->left != NULL)
				q.push(t->left);
			if(t->right != NULL)
				q.push(t->right);
			t = q.front();
			q.pop();
		}
		if(!q.empty())
			q.push(NULL);
	}
}