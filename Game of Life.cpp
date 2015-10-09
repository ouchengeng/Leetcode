class Solution {
public:
void gameOfLife(vector<vector<int>>& board)
{
	if(board.size() == 0 || board[0].size() == 0)
		return;
	int dir[8][2] = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
	int n = board.size(), m = board[0].size();
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			int live = 0;
			for(int k = 0; k < 8; k++)
			{
				int x = i + dir[k][0];
				int y = j + dir[k][1];
				if(x < 0 || x >= n || y < 0 || y >= m)
					continue;
				if(board[x][y] & 1 == 1)
				    live++;
			}
			if(board[i][j]  == 0)
			{
				if(live == 3)
					board[i][j] = 2;
			}
			else
			{
				if(live == 2||live == 3)
					board[i][j] = 3;
				else
					board[i][j] = 1;
			}
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			board[i][j] >>= 1;

}
};