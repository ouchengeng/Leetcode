class Solution {
public:
struct node
{
	char c;
	bool leaf;
	node *next[26];
	node()
	{
		leaf = false;
		for(int i = 0; i < 26; i++)
			next[i] = NULL;
	}
};
node *root;
void insert(string &s)
{
	node *p = root;
	for(int i = 0; i < s.length(); i++)
	{
		if(p->next[s[i] - 'a'] == NULL)
		{
			node *n = new node();
			n->c = s[i];
			p->next[s[i] - 'a'] = n;
		}
		if(i == s.length() - 1)
			(p->next[s[i] - 'a'])->leaf = true;
		p = p->next[s[i] - 'a'];
	}
};
int prefix(string &s)
{
	node *p = root;
	for(int i = 0; i < s.length(); i++)
	{
		if(p->next[s[i] - 'a'] == NULL)
			return 0;
		p = p->next[s[i] - 'a'];
	}
	if(p->leaf)
		return 2;
	return 1;	
};
void dfs(vector<vector<char> > &board, int x, int y, string s, unordered_set<string> &ans, vector<vector<bool> > &vis)
{
	s = s + board[x][y];
	int flag = prefix(s);
	if(flag == 0)
		return;
	vis[x][y] = true;
	if(flag == 2)
		ans.insert(s);
	int n = board.size();
	int m = board[0].size();
	if(y != 0 && vis[x][y - 1] == false)
		dfs(board, x, y - 1, s, ans, vis);
	if(x != 0 && vis[x-1][y] == false)
		dfs(board, x - 1, y, s, ans, vis);
	if(x != n - 1 && vis[x+1][y] == false)
		dfs(board, x + 1, y, s, ans, vis);
	if(y != m - 1 && vis[x][y+1] == false)
		dfs(board, x, y + 1, s, ans, vis);
	vis[x][y] = false;
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ans;
    if(board.size() == 0 || board[0].size() == 0)
    	return ans;
    root = new node();
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    for(int i = 0; i < words.size(); i++)
    	insert(words[i]);
    unordered_set<string> st;
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < m; j++)
    		dfs(board, i, j, "", st, vis);
    for(unordered_set<string>::iterator it = st.begin(); it != st.end(); it++)
        ans.push_back(*it);
    return ans;

}
};