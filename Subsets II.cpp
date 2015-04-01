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
    	int end = n;
        while( ((end + 1) < s.size()) && (s[end + 1] == s[end]))
    		end++;
    
    	end -= n;
    	for(int i = 0; i <= end + 1; i++)
    	{
    		vector<int> tmp(cur);
    		for(int j = 0; j < i; j++)
    			tmp.push_back(s[n]);
    		dfs(s, tmp, n + end + 1);
    	}
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S){
        if(S.empty())
        	return ans;
        sort(S.begin(), S.end());
        vector<int> cur;
        dfs(S, cur, 0);
        return ans;
    }
};