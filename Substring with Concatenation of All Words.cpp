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