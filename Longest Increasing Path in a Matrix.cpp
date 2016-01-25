class Solution {
public:

int bx, by;
int **dp;
int dfs(int x, int y, vector<vector<int>>& m)
{
    if(dp[x][y] != 0)
        return dp[x][y];
    dp[x][y] = 1;
    int tmp = 0;
    if(x != 0 && m[x-1][y] < m[x][y])
        tmp = max(tmp, dfs(x-1, y, m));
    if(y != 0 && m[x][y-1] < m[x][y])
        tmp = max(tmp, dfs(x, y-1, m));
    if(x != bx-1 && m[x+1][y] < m[x][y])
        tmp = max(tmp, dfs(x+1, y, m));
    if(y != by-1 && m[x][y+1] < m[x][y])
        tmp = max(tmp, dfs(x, y+1, m));
    dp[x][y] += tmp;
    return dp[x][y];
};

int longestIncreasingPath(vector<vector<int>>& matrix)
{
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return 0;   
    bx = matrix.size();
    by = matrix[0].size();
    dp = new int*[bx];
    for(int i = 0; i < bx; i++)
    {
        dp[i] = new int[by];
        memset(dp[i], 0, sizeof(int)*by);
    }
    int ans = 0;
    for(int i = 0; i < bx; i++)
        for(int j = 0; j < by; j++)
            ans = max(dfs(i, j, matrix), ans);
    return ans;
}
};
//the second one

struct node
{
    int x,y;
    int value;
};
class Solution {
public:
static bool cmp(node &a, node &b)
{
    return a.value < b.value;
}


int longestIncreasingPath(vector<vector<int>>& matrix)
{
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return 0;
    int len = matrix.size() * matrix[0].size();
    vector<node> *vv = new vector<node>(len);
    vector<node> &v = *vv;
    vector<vector<int>> &m = matrix;
    int lx = matrix.size(), ly = matrix[0].size();
    int base = max(m.size(), m[0].size());
    int pos = 0;
    for(int i = 0; i < m.size(); i++)
        for(int j = 0; j < m[i].size(); j++)
        {
            v[pos].x = i,  v[pos].y = j;
            v[pos].value = m[i][j];
            ++pos;
        }
    sort(v.begin(), v.end(), cmp);
    vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), 1));
    int res = 1;
    for(int i = 0; i < len; i++)
    {
        int x = v[i].x;
        int y = v[i].y;
        if(y != 0 && m[x][y-1] < m[x][y])
            ans[x][y] = max(ans[x][y], ans[x][y-1]+1);
        if(x != 0 && m[x-1][y] < m[x][y])
            ans[x][y] = max(ans[x][y], ans[x-1][y]+1);
        if(y != m[0].size()-1 && m[x][y+1] < m[x][y])
            ans[x][y] = max(ans[x][y], ans[x][y+1]+1);
        if(x != m.size()-1 && m[x+1][y] < m[x][y])
            ans[x][y] = max(ans[x][y], ans[x+1][y]+1);
        res = max(res, ans[x][y]);
    }
    return res;
}
};