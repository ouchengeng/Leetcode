class Solution {
public:
    vector<char> vec[10];
    void dfs(int cur, string &digits, string &s,  vector<string> &ans)
    {
    	if(cur == digits.length())
    	{
    		ans.push_back(s);
    		return;
    	}
    	for(int i = 0; i < vec[digits[cur] - '2'].size(); i++)
    	{
    		s[cur] = vec[digits[cur] - '2'].at(i);
    		dfs(cur + 1, digits, s, ans);
    	}
    }
    vector<string> letterCombinations(string digits)
    {
    	vector<string> ans;
    	if(digits.length() == 0)
    		return ans;
    	char c = 'a';
    	for(int i = 0; i <= 4; i++)
    		for(int j = 0; j < 3; j++)
    		{
    			vec[i].push_back(c);
    			c++;
    		}
    	vec[5].push_back('p');vec[5].push_back('q');vec[5].push_back('r');vec[5].push_back('s');
    	vec[6].push_back('t');vec[6].push_back('u');vec[6].push_back('v');
    	vec[7].push_back('w');vec[7].push_back('x');vec[7].push_back('y');vec[7].push_back('z');
    	string s(digits.length(), 'a');
    	dfs(0, digits, s,  ans);
    	return ans;
    }
};