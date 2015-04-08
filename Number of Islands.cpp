class Solution {
public:
queue<int> q1, q2;

void visit(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &vis)
{
	if(vis[x][y] == false && grid[x][y] == '1')
	{
		vis[x][y] = true;
		q1.push(x), q2.push(y);
	}
}
void isIsLands(int x, int y, int m, int n, vector<vector<char>> &grid, vector<vector<bool>> &vis)
{
	q1.push(x);
	q2.push(y);
	vis[x][y] = true;
	while(!q1.empty())
	{
		int i = q1.front(), j = q2.front();
		q1.pop(), q2.pop();
		int vis_i, vis_j;

		// below
		if(i != m - 1)
			visit(i + 1, j, grid, vis);

		//above
		if(i != 0)
		{
			visit(i - 1, j, grid, vis);
		}

		//left
		if(j != 0)
		{
			visit(i, j - 1, grid, vis);
		}
		//right
		if(j != n - 1)
			visit(i, j + 1, grid, vis);
	}
}
int numIslands(vector<vector<char>> &grid) 
{
	int m = grid.size();
	if(m == 0)
		return 0;
	int n = grid[0].size();
	vector<vector<bool> >  vis(m, vector<bool>(300, 0));
	int ans = 0;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			if(grid[i][j] == '1' && !vis[i][j])
			{
				ans++;
				isIsLands(i, j, m, n, grid, vis);
			}
	return ans;
}
};