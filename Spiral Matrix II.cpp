class Solution {
public:
    void generator(int startPos, int n, int counter, vector<vector<int> > &ans)
    {
    	if(n <= 0)
    		return;
    	int x1 = startPos, x2 = startPos + n - 1;
    	for(int i = x1; i <= x2; i++)
    		ans[x1][i] = counter++;
    	for(int i = x1 + 1; i <= x2; i++)
    		ans[i][x2] = counter++;
    	for(int i = x2 - 1; i >= x1; i--)
    		ans[x2][i] = counter++;
    	for(int i = x2 - 1; i > x1; i--)
    		ans[i][x1] = counter++;
    	generator(startPos + 1, n - 2, counter, ans);
    }
    vector<vector<int> > generateMatrix(int n)
    {
    	vector<vector<int> > ans(n, vector<int>(n, 0));
    	generator(0, n, 1, ans);
    	return ans;
    }
};