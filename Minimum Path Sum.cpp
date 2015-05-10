class Solution {
public:
int minPathSum(vector<vector<int>>& grid)
{
	if(grid.size() == 0 || grid[0].size() == 0)
		return 0;
	int m = grid.size();
	int n = grid[0].size();
	int dp[n][2];
	for(int i = 0; i < m; i++)
	{
		int cur = i % 2;
		int last = (i + 1) % 2;
		for(int j = 0; j < n; j++)
		{
			if(i == 0)
				dp[j][cur] = grid[i][j] + ((j == 0) ? 0 : dp[j - 1][cur]);
			else if(j == 0)
				dp[j][cur] = grid[i][j] + dp[j][last];
			else 
				dp[j][cur] = min(dp[j][last], dp[j - 1][cur]) + grid[i][j];
		}
	}
	return dp[n - 1][(m - 1) % 2];
}
};