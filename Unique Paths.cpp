class Solution {
public:
    int uniquePaths(int m, int n)
    {
    	if(m + n == 0)
    		return 0;
    	else if(m * n == 0)
    		return m + n;
    	vector<vector<int>> dp(2, vector<int>(n + 1, 0));
    	for(int i = 1; i <= m; i++)
    	{
    		int cur = i % 2;
    		int last = (i + 1) % 2;
    		for(int j = 1; j <= n; j++)
    		{
    			if(i == 1)
    				dp[cur][j] = 1;
    			else if(j == 1)
    				dp[cur][j] = dp[last][j];
    			else
    				dp[cur][j] = dp[cur][j - 1] + dp[last][j];
    		}
    	}
    	return dp[m % 2][n];
    }
};