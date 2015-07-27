class Solution {
public:
    string multiply(string num1, string num2)
    {
    	if(num1.length() == 0 || num2.length() == 0)
    		return "";
    	string ans(num1.length() + num2.length(), '0');
    	for(int i = num1.size() - 1; i >= 0; i--)
    	{
    		int carry = 0;
    		for(int j = num2.size() - 1; j >= 0; j--)
    		{
    			int tmp = (ans[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
    			ans[i+j+1] = tmp % 10 + '0';
    			carry = tmp / 10;
    		}
    		ans[i] += carry;
    	}
    	int startops = ans.find_first_not_of("0");
    	if(startops != -1)
    		return ans.substr(startops);
    	return "0";
    }
};