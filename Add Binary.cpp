class Solution {
public:
string add(string a, string b)
{
	// a.length > b.length
	// a 11
	// b  1
	ostringstream out;
	int flag = 0, mod = 2;
	for(int i = a.length()-1, j = b.length() - 1; i >= 0; i--, j--)
	{
		int ac = a[i] - '0';
		int bc = (j >= 0 ? b[j] : '0') - '0';
		int sum = ac + bc + flag;
		out<<sum % mod;
		flag = sum / mod;
	}
	if(flag)
		out<<flag;
	string ans = out.str();
	for(int i = 0, j = ans.length() - 1; i < j; i++, j--)
	{
		char c = ans[i];
		ans[i] = ans[j];
		ans[j] = c;
	}
	return ans;

}

string addBinary(string a, string b) {
    int m = a.length();
    int n = b.length();
    if(m == 0)
        return b;
    else if(n == 0)
        return a;
    if(m > n)
    	return add(a, b);
    else
    	return add(b, a);
}
};