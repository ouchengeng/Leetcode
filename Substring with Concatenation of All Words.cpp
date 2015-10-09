class Solution {
public:
vector<int> findSubstring(string S, vector<string> &L) 
{
	vector<int> ans;
	if(S.length() == 0|| L.size() == 0)
		return ans;
	unordered_map<string, int> dic;
	unordered_map<string, int>::iterator it_dic;
	for(int i = 0; i < L.size(); i++)
		dic[L[i]]++;
	int len = L[0].size(), num = dic.size(), cur = 0, left = 0;
	for(int i = 0; i < len; i++)
	{
		int pos = i;
		cur = 0;
		left = i;
		unordered_map<string, int> tmp;
		unordered_map<string, int>::iterator it_tmp;
		for(int j = i; j < S.length() - len + 1; j += len)
		{
			string s1 = S.substr(j, len);
			it_dic = dic.find(s1);
			if(it_dic == dic.end())
			{
				cur = 0;
				tmp.clear();
				continue;
			}
			else
			{
				it_tmp = tmp.find(s1);
				int count = 0;
				if(it_tmp == tmp.end())
				{
					count = 1;
					tmp.insert(make_pair(s1, 1));
				}
				else
				{
					it_tmp->second++;
					count = it_tmp->second;
				}
				int match = it_dic->second;
				if(match == count)
					cur++;
				else if(count > match)
				{
					string st  = s1;
					while(tmp[s1] > dic[s1])
					{
						st = S.substr(left, len);
						if(tmp.find(st) != tmp.end())
						{
							tmp[st]--;
							if(tmp[st] < dic[st])
								cur--;
						}
						left += len;
					}
				}
				if(cur == num)
					ans.push_back(j - (L.size() - 1) * len);
			}
		}
	}
	return ans;
}
};


//////////////
/// another Solution
//
class Solution {
public:
vector<int> ans;
unordered_map<string, int> m, m1;
void solve(int start, string &s, vector<string> &words)
{
	//m stores info, m1 stores current info
	unordered_map<string, int>::iterator it;
	int p1 = start, p2 = start, len = words[0].length(), cur = 0;
	m1.clear();
	while(p2 + len - 1 < s.length())
	{
		while(cur != m.size() && p2 + len - 1 < s.length())
		{
			string tmp = s.substr(p2, len);
			it = m.find(tmp);
			if(it == m.end())
			{
				p2 += len;
				p1 = p2;
				cur = 0;
				m1.clear();
				continue;
			}
			else if(it->second == m1[tmp])
			{
			    string tmp2 = "";
			    while(p1 != p2 && tmp2 != tmp)
			    {
			        tmp2 = s.substr(p1, len);
			        if(m1.find(tmp2) != m1.end())
			        {
			            if(m1[tmp2] == m[tmp2])
			                cur--;
			            m1[tmp2]--;
			        }
			        p1 += len;
			    }
			    continue;
			}
			m1[tmp]++;
			if(it->second == m1[tmp])
				cur++;
			p2 += len;
		}
		while(cur == m.size() && p1 <= p2)
		{
			ans.push_back(p1);
			string tmp = s.substr(p1, len);
			it = m1.find(tmp);
			if(it == m1.end())
			{
				p1 += len;
				continue;
			}
			it->second--;
			if(it->second < m[tmp])
				cur--;
			p1 += len;
		}
	}
}
vector<int> findSubstring(string s, vector<string>& words)
{
	if(s.length() == 0 || words.size() == 0)
		return ans;
	int cur = 0;
	for(int i = 0; i < words.size(); i++)
		m[words[i]]++;
	m1 = m;
	int p1 = 0, p2 = 0;
	for(int i = 0; i < words[0].length(); i++)
		solve(i, s, words);
	return ans;
}
};
