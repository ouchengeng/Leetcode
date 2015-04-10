class Solution {
public:
int n, m;
bool dfs(int x, int y, int pos, vector<vector<char>> &b, string &s)
{
	if(pos == s.length())
		return true;
	if(x < 0 || y < 0 || x >= m || y >= n || b[x][y] == '\0' || s[pos] != b[x][y])
		return false;
	char c = b[x][y];
	b[x][y]= '\0';
	pos++;
	if(dfs(x - 1, y, pos, b, s) 
		|| dfs(x + 1, y, pos, b, s) 
		|| dfs(x, y - 1, pos, b, s) 
		|| dfs(x, y + 1, pos, b, s))
		return true;
	b[x][y] = c;
	return false;
}
bool exist(vector<vector<char> > &board, string word)
{
	if(board.size() == 0 || board[0].size() == 0)
		return 0;
	m = board.size();
	n = board[0].size();

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			if(dfs(i, j, 0, board, word))
				return true;
	return false;

}
};