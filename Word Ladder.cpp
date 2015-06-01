class Solution {
public:
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
	int ans = 1;
	unordered_set<string> far, back, *set1, *set2;
	far.insert(beginWord);
	back.insert(endWord);
	int len = beginWord.size();
	while(!far.empty() && !back.empty())
	{
		if(far.size() <= back.size())
		{
			set1 = &far;
			set2 = &back;
		}
		else
		{
			set1 = &back;
			set2 = &far;
		}
		ans++;
		unordered_set<string> middle;
		for(unordered_set<string>::iterator it = set1->begin(); it != set1->end(); it++)
		{
			string s = *it;
			for(int i = 0; i < len; i++)
			{
				char c = s[i];
				for(int j = 0; j < 26; j++)
				{
					s[i] = 'a' + j;
					if(set2->find(s) != set2->end())
						return ans;
					if(wordDict.find(s) != wordDict.end())
					{
						middle.insert(s);
						wordDict.erase(s);
					}
				}
				s[i] = c;
			}
		}
		set1->clear();
		for(unordered_set<string>::iterator it = middle.begin(); it != middle.end(); it++)
			set1->insert(*it);
	}
	return 0;
}
};