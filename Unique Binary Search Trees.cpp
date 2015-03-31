class Solution {
public:
int numTrees(int n) {
	if(n == 0)
		return 0;
	vector<int> dp(n + 1);
	dp[1] = 1;
	dp[2] = 2;
	dp[0] = 1;
	for(int i = 3; i <= n; i++)
	{
		// compute i
		int ans = 0;
		for(int mid = 1; mid <= i; mid++)
		{
			int left = mid - 1;
			int right = i - mid;
			ans += dp[left] * dp[right];
		}
		dp[i] = ans;
	}
	return dp[n];
}
};