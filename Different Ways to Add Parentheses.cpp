class Solution {
public:
    unordered_map<string, vector<int>> dp;
    void computer(string s)
    {
    	vector<int> vec;
    	bool find = false;
    	for(int i = 0; i < s.length(); i++)
    	{
    		if(s[i] == '+' || s[i] == '-' || s[i] == '*')
    		{
    			find = true;
    			string pre = s.substr(0, i);
    			string after = s.substr(i + 1);
    			if(dp.find(pre) == dp.end())
    				computer(pre);
    			if(dp.find(after) == dp.end())
    				computer(after);
    			for(int j = 0; j < dp[pre].size(); j++)
    				for(int k = 0; k < dp[after].size(); k++)
    				{
    					if(s[i] == '+')
    						vec.push_back(dp[pre][j] + dp[after][k]);
    					if(s[i] == '-')
    						vec.push_back(dp[pre][j] - dp[after][k]);
    					if(s[i] == '*')
    						vec.push_back(dp[pre][j] * dp[after][k]);
    				}
    		}
    	}
    	if(!find)
    	{
    		int num = 0;
    		for(int i = 0; i < s.length(); i++)
    			num = num * 10 + s[i] - '0';
    		vec.push_back(num);
    	}
    	dp.insert(make_pair(s, vec));
    }
    vector<int> diffWaysToCompute(string input)
    {
    	computer(input);
    	return dp[input];
    }
};