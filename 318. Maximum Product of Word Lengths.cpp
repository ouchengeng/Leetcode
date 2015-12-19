class Solution {
public:
int maxProduct(vector<string>& words)
{
	int n = words.size();
	if(n <= 1)
		return 0;
	vector<unsigned long> h(n, 0);
	for(int i = 0; i < n; i++)
	{
		int tmp = words[i].length();
		bitset<26> bs;
		for(int j = 0; j < tmp; j++)
			bs.set(words[i][j] - 'a');
		h[i] = bs.to_ulong();
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i != j && ((h[i] & h[j]) == 0) && words[i].length() * words[j].length() > ans)
				ans = words[i].length() * words[j].length();
	return ans;
}
};