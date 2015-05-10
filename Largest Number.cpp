class Solution {
public:
static bool cmp(const string &s1, const string &s2)
{
	if(s1.length() == s2.length())
		return s1 > s2;
	else
		return (s1 + s2) > (s2 + s1);
}
string largestNumber(vector<int> &num)
{
	vector<string> s(num.size());
	ostringstream ss;
	for(int i = 0; i < num.size(); i++)
	{
		ss<<num[i];
		s[i] = ss.str();
		ss.str("");
	}
	sort(s.begin(), s.end(), cmp);
	for(int i = 0 ; i < s.size(); i++)
		ss<<s[i];
	string ans = ss.str();
	if(ans.length() > 0 && ans[0] == '0')
		return "0";
	return ans;
}
};