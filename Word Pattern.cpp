class Solution {
public:
unordered_map<string, int> m1;
unordered_map<int, string> m2;
bool judge(int n, string &s)
{
	unordered_map<string, int>::iterator it1 = m1.find(s);
	unordered_map<int, string>::iterator it2 = m2.find(n);
	if(it1 == m1.end() && it2 != m2.end())
		return false;
	else if(it1 != m1.end() && it2 == m2.end())
		return false;
	else if(it1 == m1.end() && it2 == m2.end())
	{
		m1[s] = n;
		m2[n] = s;
		return true;
	}
	else
	{
		string s1 = it1->first, s2 = it2->second;
		if(it1->second == it2->first && s1.compare(s2) == 0)
			return true;
		return false;
	}

}
bool wordPattern(string pattern, string str)
{
	string m[26] = {""};
	int pre = 0, i = 0, pos = 0;
	while(i < str.length())
	{
		if(str[i] == ' ')
		{
			string tmp = str.substr(pre, i - pre);
			if(pos >= pattern.length() || !judge(pattern[pos] - 'a', tmp))
				return false;
			pos++;
			pre = i+1;
		}
		i++;
	}
	string tmp = str.substr(pre, i - pre);
	if(pos >= pattern.length() || !judge(pattern[pos] - 'a', tmp))
		return false;
	pos++;
	if(pos < pattern.length())
		return false;
	return true;
}
};