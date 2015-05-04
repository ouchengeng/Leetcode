class Solution {
public:
int longestValidParentheses(string s)
{
    int n = s.length();
    if(n <= 1)
        return 0;
    vector<int> dp(n + 1, 0); //dp[i]记录以i结尾的最长子串
    for(int i = 1; i < n; i++)
    {
        if(s[i] == '(')
            continue;
        int match = i - dp[i - 1] - 1;
        if(match >= 0 && s[match] == '(')
        {
            dp[i] = dp[i - 1] + 2;
            if(match - 1 > 0)
                dp[i] += dp[match - 1];
        }
    }
    int ans = 0;
    for(int i = 1; i < n; i++)
        if(ans < dp[i])
            ans = dp[i];
    return ans;
}
};