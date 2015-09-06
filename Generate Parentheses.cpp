class Solution {
private:
    vector<string> ans;
public:
    void dfs(int cur, int left, int right, string &s)
    {
        if(cur == s.length())
        {
            if(left == right)
                ans.push_back(s);
            return;
        }
        s[cur] = '(';
        dfs(cur+1, left+1, right, s);
        if(left > right)
        {
            s[cur] = ')';
            dfs(cur+1, left, right+1, s);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s(2*n, '(');
        dfs(0, 0, 0, s);
        return ans;
    }
};