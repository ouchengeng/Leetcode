class Solution {
public:
vector<int> grayCode(int n)
{
	vector<int> tmp;
	if(n == 1)
	{
		tmp.push_back(0), tmp.push_back(1);
		return tmp;
	}
	else if(n == 0)
	{
	    tmp.push_back(0);
		return tmp;
	}
	tmp = grayCode(n-1);
	vector<int> ans = tmp;
	for(int i = tmp.size()-1; i >= 0; i--)
		ans.push_back(tmp[i] + (1 << (n-1)));
	return ans;
}
};