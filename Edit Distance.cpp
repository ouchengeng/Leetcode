class Solution {
public:
int min(int a, int b, int c)
{
	if(b > c)
		b = c;
	return a < b ? a : b;
}
int minDistance(string word1, string word2) 
{
    int m = word1.length();
	int n = word2.length();
    if(m * n == 0)
        return m + n;
    int dp[m+1][n+1];
	for(int i = 0; i <= m; i++)
		dp[i][0] = i;
	for(int i = 0; i <= n; i++)
		dp[0][i] = i;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
		{
			int a = dp[i][j - 1] + 1;
			int b = dp[i - 1][j] + 1;
			int c = dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1);
			dp[i][j] = min(a, b, c);
		}
	return dp[m][n];
}
};