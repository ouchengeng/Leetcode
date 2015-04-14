int removeDuplicates(int A[], int n) 
{
	if(n <= 1)
		return n;
	int pos = 2;
	int pre1 = A[1], pre2 = A[0];
	for(int i = 2; i < n; i++)
	{
		if(A[i] != pre1 || A[i] != pre2)
			A[pos++] = A[i];
		pre2 = pre1;
		pre1 = A[i];
	}
	return pos;
}