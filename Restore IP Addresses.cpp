class Solution {
public:
bool isValid(string &s, int left, int end)
{
	if((s[left] == '0' && end != left) || (left > end))
		return false;
	int ans = 0;
	for(int i = left; i <= end; i++)
		ans = ans * 10 + s[i] - '0';
	if(ans >= 0 && ans <= 255)
		return true;
	return false;
}

void dfs(vector<string> &ans, string &s, int cur, int left, string &tmp)
{
	if(left >= s.length())
		return;
	if(cur == 4)
	{
		if(isValid(s, left, s.length() - 1))
		{
			tmp = tmp + s.substr(left);
			ans.push_back(tmp);

		}
	}
	else
	{
		int j = 4;
		for(int i = 0; i < j && left + i < s.length(); i++)
		{
			int remains = s.length() - (left + i + i);
			if(remains > (j - cur) * j + 1)
				continue;

			if(isValid(s, left, left + i))
			{
				string tmp1 = tmp + s.substr(left, i + 1) + ".";
				dfs(ans, s, cur + 1, left + i + 1, tmp1);
			}
		}
	}
}
vector<string> restoreIpAddresses(string s) 
{
	vector<string> ans;
	if(s.length() < 4)
		return ans;
	string t = "";
	dfs(ans, s, 1, 0, t);
	return ans;
}
};