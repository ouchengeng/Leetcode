class Solution {
public:
vector<vector<string> > ans;
vector<string> tmp;
bool isPalindrome(int l, int r, string &s)
{
	while (l < r)
		if (s[l++] != s[r--])
			return false;
	return true;
}
void dfs(int pos, int len, string &s)
{
	if (pos >= len)
		ans.push_back(tmp);
	for (int i = pos; i < len; i++)
		if (isPalindrome(pos, i, s))
		{
			tmp.push_back(s.substr(pos, i - pos + 1));
			dfs(i + 1, len, s);
			tmp.pop_back();
		}
}
vector<vector<string>> partition(string s) 
{
	int len = s.length();
	if (len == 0)
		return ans;
	dfs(0, len, s);
	return ans;
}
};