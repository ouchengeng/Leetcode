class Solution {
public:
int rob(vector<int> &num) 
{
	if(num.size() == 0)
		return 0;
	bool vis2 = false, vis1 = true;
	int ans2 = 0, ans1 = num[0];
	// vis2 vis1
	// ans2 ans1
	for(int i = 1; i < num.size(); i++)
	{
		int cur;
		bool vis;
		if(vis1 == false)
		{
			cur = num[i] + ans1;
			vis = true;
		}
		else
		{
			int join = ans2 + num[i]; 
			if(join <= ans1) //
			{
				cur = ans1;
				vis = false;
			}
			else
			{
				cur = join;
				vis =true;
			}
		}
		ans2 = ans1, vis2 = vis1;
		ans1 = cur,  vis1 = vis;
	}
	return ans1;
}
};