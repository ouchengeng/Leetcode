int searchInsert(int A[], int n, int target) 
{
	if(n == 0)
		return 0;
	int low = 0, high = n - 1, mid;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(A[mid] == target)
			return mid;
		else if(target < A[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	if(low == mid)
		return mid;
	if(high == mid)
		return mid+ 1;
}