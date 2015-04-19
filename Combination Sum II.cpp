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
    
    	int next_pos = pos + 1;
    	for(; next_pos < candidates.size(); next_pos++)
    		if(candidates[next_pos] != candidates[next_pos - 1])
    			break;
    	// next_pos reperesents the next different value.
    	// pos ... next_pos-1 is the same
    	dfs(next_pos, sum, cur, ans, candidates, target);
    	for(int i = pos; i < next_pos; i++)
    	{
    		cur.push_back(candidates[pos]);
    		sum += candidates[pos];
    		dfs(next_pos, sum, cur, ans, candidates, target);
    		cur.pop_back();
    	}
    	for(int i = pos; i < next_pos; i++)
    		cur.pop_back();
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target)
    {
    	sort(num.begin(), num.end());
    	vector<vector<int> > ans;
    	vector<int > cur;
    	dfs(0, 0, cur, ans, num, target);
    	return ans;
    }
};