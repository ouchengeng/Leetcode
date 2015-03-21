class Solution {
public:
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
};
void solve(vector<vector<int>> &ans, vector<int> cur, int pos)
{
	if(pos == cur.size())
		return;
	if(pos == cur.size() - 1)
	{
		ans.push_back(cur);
		return;
	}
	for(int i = pos; i < cur.size(); i++)
	{
		swap(&cur[i], &cur[pos]);
		solve(ans, cur, pos+1);
		swap(&cur[i], &cur[pos]);
	}
}
vector<vector<int> > permute(vector<int> &num)
{
	vector<vector<int>> ans;
	if(num.empty())
		return ans;
	vector<int> cur(num.size());
	memcpy(&cur[0], &num[0], sizeof(int)*num.size());
	solve(ans, cur, 0);
	return ans;
}
};