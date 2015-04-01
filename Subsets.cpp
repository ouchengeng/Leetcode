class Solution {
public:
    vector<vector<int> > ans;
    void dfs(vector<int> &s, vector<int> cur, int n)
    {
    	if(n >= s.size())
    	{
    		ans.push_back(cur);
    		return;
    	}
    	dfs(s, cur, n + 1);
    	cur.push_back(s[n]);
    	dfs(s, cur, n + 1);
    }
    vector<vector<int> > subsets(vector<int> &S){
    	if(S.empty())
    		return ans;
    	sort(S.begin(), S.end());
    	vector<int> cur;
    	dfs(S, cur, 0);
    	return ans;
    }
};


// another solution by bitmanipulation
class Solution {
public:
    vector<vector<int> > ans;
    void dfs(vector<int> &s, int n)
    {
        vector<int> v;
        for(int i = 0; i < s.size(); i++)
        {
            int f = n & 1;
            if(f)
                v.push_back(s[i]);
            n >>= 1;
        }
        ans.push_back(v);
    }
    vector<vector<int> > subsets(vector<int> &S){
        if(S.empty())
            return ans;
        sort(S.begin(), S.end());
        long num = pow(2, (int)S.size());
        for(int i = 0; i < num; i++)
            dfs(S, i);
        return ans;
    }
};