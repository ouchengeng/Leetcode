class Solution {
public:
int calculate(string s)
{
	///(1+(4+5+2)-3)+(6+8)
	stack<int> value;
	stack<char> opt;
	int positive = 1, negative = -1;
	int num = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == ' ')
			continue;
		else if(s[i] == '+')
			opt.push('+');
		else if(s[i] == '-')
			opt.push('-');
		else if(s[i] == '*')
			opt.push('*');
		else if(s[i] == '/')
			opt.push('/');
		else
		{
			int cur = 0;
			while(i < s.length() && ((s[i] <= '9' && s[i] >= '0') || s[i] == ' '))
			{
				if(s[i] == ' ')
				{
					i++;
					continue;
				}
				cur = cur * 10 + s[i] - '0';
				i++;
			}
			i--;
			if( !opt.empty() && (opt.top() == '/' || opt.top() == '*'))
			{
				int ans = (opt.top() == '/') ? (value.top() / cur) : (value.top()*cur);
				opt.pop();
				value.pop();
				value.push(ans);
			}
			else
				value.push(cur);
		}
	}
	int ans = 0;
	while(!opt.empty())
	{
		if(opt.top() == '+')
			ans += value.top();
		else
			ans -= value.top();
		value.pop();
		opt.pop();
	}
	ans += value.top();
	return ans;
}
};