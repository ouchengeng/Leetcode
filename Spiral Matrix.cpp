class Solution {
public:
void outer(int x1, int x2, int y1, int y2, vector<vector<int> > &matrix, vector<int> &ans)
{
	if(x1 > x2 || y1 > y2)
		return;
	for(int i = y1; i <= y2; i++)
		ans.push_back(matrix[x1][i]);
    if(x1 == x2)
        return;
	for(int i = x1 + 1; i <= x2; i++)
		ans.push_back(matrix[i][y2]);
	for(int i = y2 - 1; i >= y1; i--)
		ans.push_back(matrix[x2][i]);
	if(y1 == y2)
	    return;
	for(int i = x2 - 1; i >= x1 + 1; i--)
		ans.push_back(matrix[i][y1]);
	outer(x1 + 1, x2 - 1, y1 + 1, y2 - 1, matrix, ans);
}
vector<int> spiralOrder(vector<vector<int> > &matrix)
{
	vector<int> ans;
	if(matrix.size() == 0 || matrix[0].size() == 0)
		return ans;
	outer(0, matrix.size() - 1, 0, matrix[0].size() - 1, matrix, ans);
	return ans;
}
};