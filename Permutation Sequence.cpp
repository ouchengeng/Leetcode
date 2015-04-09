class Solution {
public:
string ans;

void topDown(int n, int k, vector<int> &v, vector<int> &n1)
{
	if(n == 0)
	    return;
	int count = n1[n - 1];
	int index = k / count;
	int mode = k % count;
	if(mode != 0)
		index++;
	ans += v[index] + '0';
	v.erase(v.begin() + index, v.begin() + index + 1);
	k = k - count * (index - 1);
	topDown(n - 1, k, v, n1);
}
string getPermutation(int n, int k)
{
	vector<int> n1;
	n1.push_back(1);
	n1.push_back(1);
	for(int i = 2; i <= n; i++)
		n1.push_back(i * n1[i - 1]);
	vector<int> v;
	for(int i = 0; i <= n; i++)
		v.push_back(i);
	topDown(n, k, v, n1);
	return ans;
}
};