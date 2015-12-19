class Solution {
public:
static bool string_sort(string &s1, string &s2)
{
	return s1.length() > s2.length();
}
int maxProduct(vector<string>& words)
{
	int n = words.size();
	if(n <= 1)
		return 0;
	sort(words.begin(), words.end(), string_sort);
	vector<unsigned int> h(n, 0);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < words[i].length(); j++)
		    h[i] |= 1 << (words[i][j] - 'a');
	int ans = 0;
	for(int i = 0; i < n - 1; i++)
	{
	    if(words[i].length() * words[i+1].length() <= ans)
	        break;
		for(int j = i + 1; j < n; j++)
			if(((h[i] & h[j]) == 0))
			{
				int tmp = words[i].length() * words[j].length();
				ans = max(ans, tmp);
				break;
			}
	}
	return ans;
}
};