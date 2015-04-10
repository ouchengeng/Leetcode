class Solution {
public:
vector<vector<int> > ans;
int maxN;
void dfs(int n, int k, vector<int> vec)
{
    if(k == 0)
    {
        ans.push_back(vec);
        return;
    }
	if(n > maxN || (maxN - n + 1) + vec.size() < k)
		return;
	//start from n, and choose k numbers

	//not choose current value
	dfs(n + 1, k, vec);

	//choose current value
	vec.push_back(n);
	dfs(n + 1, k - 1, vec);
}
vector<vector<int> > combine(int n, int k) {
	vector<int> tmp;
	maxN = n;
	dfs(1, k, tmp);
	return ans;
}
};