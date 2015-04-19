class Solution {
public:
    void dfs(int pos, int sum, vector<int> &cur, vector<vector<int> > &ans, vector<int> &candidates, int target)
    {
    	if(sum == target)
    	{
    		ans.push_back(cur);
    		return;
    	}
    	if(pos >= candidates.size() || sum > target)
    		return;
    	dfs(pos + 1, sum, cur, ans, candidates, target);
    	int counter = 0;
    	while(sum < target)
    	{
    		counter++;
    		cur.push_back(candidates[pos]);
    		sum += candidates[pos];
    		dfs(pos + 1, sum, cur, ans, candidates, target);
    	}
    	for(int i = 0; i < counter; i++)
    		cur.pop_back();
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
    	sort(candidates.begin(), candidates.end());
    	vector<vector<int> > ans;
    	vector<int> cur;
    	dfs(0, 0, cur, ans, candidates, target);
    	return ans;
    }
};