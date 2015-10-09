class Solution {
public:
int numDistinct(string s, string t)
{
	//dp[i][j] 
	int n = s.length(), m = t.length();
	if(n == 0 || m == 0)
		return 0;
	int dp[n][m];
	memset(dp, 0, sizeof(dp));
	//vector<vector<int>> dp(n, vector<int>(m, 0));
	//dp[i][0]
	for(int i = 0; i < n; i++)
	{
		dp[i][0] = (i == 0) ? 0 : dp[i-1][0];
		if(s[i] == t[0])
			dp[i][0]++;
	}
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j < m; j++)
		{
			dp[i][j] = dp[i-1][j];
			if(s[i] == t[j] && i > 0 && j > 0)
				dp[i][j] += dp[i-1][j-1];
		}
	}
	return dp[n-1][m-1];
}
};