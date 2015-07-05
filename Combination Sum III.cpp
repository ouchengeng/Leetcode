class Solution {
public:
    void dfs(vector<int> &tmp, vector<vector<int> > &ans, int k, int cur, int n, int sum, int value)
    {
    	if(sum == n && k == cur)
    	{
    		ans.push_back(tmp);
    		return;
    	}
    	if(cur > k || sum > n || value > 9)
    		return;
    	dfs(tmp, ans, k, cur, n, sum, value + 1);
    	tmp.push_back(value);
    	dfs(tmp, ans, k, cur + 1, n, sum += value, value + 1);
    	tmp.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> tmp;
    	vector<vector<int> > ans;
    	dfs(tmp, ans, k, 0, n, 0, 1);
    	return ans;
    }
};