class Solution {
public:
int minCut(string s) 
{
	int len = s.length();
	if (len <= 1)
		return 0;
	vector<vector<bool> > dp(len, vector<bool>(len, false));
	vector<int> ans(len, 0);
	for (int i = 0; i < len; i++)
		dp[i][i] = true;
	for (int i = 1; i < len; i++)
	{
		ans[i] = ans[i - 1] + 1;
		for (int j = 0; j < i; j++)
		{
			//判断j到i是不是回文
			if (s[i] == s[j] && (j == i - 1 || dp[j + 1][i - 1]))
			{
			    dp[j][i] = true;
				if (j == 0)
				{
					ans[i] = 0;
					if(i == len - 1)
					    break;
				}
				else if (ans[i] > ans[j - 1] + 1)
					ans[i] = ans[j - 1] + 1;
			}
		}
	}
	return ans[len - 1];
}
};