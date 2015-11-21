struct node
{
	int left, right;
	int sum;
	node () {
	    left = -1;
	    right  = -1;
		sum = 0;
	}
};
class NumArray {
private:
	node *root;
	void buildTree(vector<int> &nums, int left, int right, int pos)
	{
		if(left > right)
			return;
		root[pos].left = left;
		root[pos].right = right;
		if(left == right)
		{
			root[pos].sum = nums[left];
			return;
		}
		int split = (left + right) >> 1;
		buildTree(nums, left, split, pos<<1);
		buildTree(nums, split+1, right, (pos<<1) + 1);
		root[pos].sum = root[pos<<1].sum + root[(pos<<1)+1].sum;
	}

	int query(int left, int right, int pos)
	{
	    if(root[pos].left > right || root[pos].right < left)
	        return 0;
		if(root[pos].left == left && root[pos].right == right)
			return root[pos].sum;
		int split = root[pos<<1].right;
		if(split >= right)
			return query(left, right, pos<<1);
		else if(split < left)
			return query(left, right, (pos<<1)+1);
		else
			return query(left, split, pos<<1) + query(split + 1, right, (pos<<1) + 1);
	}

	void updateValue(int index, int value, int pos)
	{
		if(root[pos].left > index || root[pos].right < index)
			return;
		if(root[pos].left == index && root[pos].right == index)
		{
			root[pos].sum = value;
			return;
		}
		updateValue(index, value, pos<<1);
		updateValue(index, value, (pos<<1)+1);
		root[pos].sum = root[pos<<1].sum + root[(pos<<1)+1].sum;
	}
public:
    NumArray(vector<int> &nums) {
        int size = nums.size();
		root = new node[size*4];
		buildTree(nums, 0, size-1, 1);
    }
    void update(int i, int val) {
        updateValue(i, val, 1);
    }

    int sumRange(int i, int j) {
        return query(i, j, 1);
    }
};