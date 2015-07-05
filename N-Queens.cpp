class Solution {
public:
    bool valid(vector<string> &queues, int row, int col, int n)
    {
    	for(int i = 0; i != row; i++)
    		if(queues[i][col] == 'Q')
    			return false;
    	for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
    		if (queues[i][j] == 'Q')
    			return false;
    	//check if the 135° diagonal` had a queen before.
    	for(int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
    		if (queues[i][j] == 'Q')
    			return false;
        return true;
    }
    void dfs(vector<vector<string> > &ans, vector<string> &queues, int cur, int n)
    {
    	if(cur == n)
    	{
    		ans.push_back(queues);
    		return;
    	}
    	//第cur行
    	for(int i = 0; i < n; i++)
    	{
    		if(valid(queues, cur, i, n))
    		{
    			queues[cur][i] = 'Q';
    			dfs(ans, queues, cur+1, n);
    			queues[cur][i] = '.';
    		}
    	}
    
    }
    vector<vector<string>> solveNQueens(int n)
    {
    	vector<string> queues(n, string(n, '.'));
    	vector<vector<string> > ans;
    	if(n <= 0)
    		return ans;
    	dfs(ans, queues, 0, n);
    	return ans;
    }
};