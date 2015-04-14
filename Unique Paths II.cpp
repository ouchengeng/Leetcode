class Solution {
public:
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) 
{
	if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
		return 0;
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
    int dp[2][n + 1];
    for(int i = 0; i <= n; i++)
        dp[0][i] = dp[1][i] = 1;
	for(int i = 1; i <= m; i++)
	{
		int cur = i % 2;
		int last = (i + 1) % 2;
		for(int j = 1; j <= n; j++)
		{
			if(obstacleGrid[i-1][j-1] == 1)
				dp[cur][j] = 0;
			else if(i == 1)
				dp[cur][j] = dp[cur][j - 1];
			else if(j == 1)
				dp[cur][j] = dp[last][j];
			else
				dp[cur][j] = dp[cur][j - 1] + dp[last][j];
		}
	}
	return dp[m % 2][n];
}
};