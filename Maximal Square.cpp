class Solution {
public:
int maximalSquare(vector<vector<char>>& matrix) {
	if(matrix.size() == 0 || matrix[0].size() == 0)
		return 0;
	int n = matrix.size();
	int m = matrix[0].size();
	int ans = 0;
	vector<vector<int> > dp(2, vector<int>(m, 0));
	for(int i = 0; i < n; i++)
	{
		int cur = i % 2;
		int last = (i + 1) % 2;
		for(int j = 0; j < m; j++)
		{
			if(matrix[i][j] == '0')
				dp[cur][j] = 0;
			else if (i == 0 || j == 0 || dp[last][j - 1] == 0)
			{
				dp[cur][j] = 1;
				ans = max(dp[cur][j], ans);
			}
			else if(dp[last][j - 1] != 0)
			{
				dp[cur][j] = min(min(dp[last][j], dp[cur][j - 1]), dp[last][j - 1]) + 1;
				ans = max(dp[cur][j], ans);
			}
		}
	}
	return ans * ans;
}
};