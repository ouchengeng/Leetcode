class Solution {
public:
bool searchMatrix(vector<vector<int> > &matrix, int target)
{
	if(matrix.size() == 0 || matrix[0].size() == 0)
		return false;
	int m = matrix.size();
	int n = matrix[0].size();
	/**
	x1******************y1
	x2******************y1
	*/
	// but we dont really have x2 or y2
	int x1 = 0, y1 = n - 1;
	while(x1 < m && y1 >= 0)
	{
		if(target == matrix[x1][y1])
			return true;
		else if(target < matrix[x1][y1])
			y1 -= 1;
		else
			x1++;
	}
	return false;
}
};


// another solution by binary search
class Solution {
public:
bool searchMatrix(vector<vector<int> > &matrix, int target)
{
	if(matrix.size() == 0 || matrix[0].size() == 0)
		return false;
	int m = matrix.size();
	int n = matrix[0].size();
	int low = 0, high = (m - 1) * n + (n - 1);
	while(low <= high)
	{
		int middle = (low + high) >> 1;
		int x = middle / n;
		int y = middle % n;
		if(matrix[x][y] == target)
			return true;
		else if(matrix[x][y] < target)
			low = middle + 1;
		else
			high = middle - 1;
	}
	return false;
}
};