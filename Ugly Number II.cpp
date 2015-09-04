class Solution {
public:
int nthUglyNumber(int n)
{
	//2^5 * 3 ^ 3
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
	int ans = 1, p2 = 0, p3 = 0, p5 = 0;
	vector<int> v(1, 1);
	for(int i = 1; i < n; i++)
	{
		ans = min(v[p2]*2, min(v[p3]*3, v[p5]*5));
		if(ans == v[p2]*2)
			p2++;
		if(ans == v[p3]*3)
			p3++;
		if(ans == v[p5]*5)
			p5++;
		v.push_back(ans);
	}
	return ans;

}
};