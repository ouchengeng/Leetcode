class Solution {
public:
    bool isHappy(int n)
    {
    	unordered_set<int> s;
    	s.insert(n);
    	while(n > 0)
    	{
    		int sum = 0;
    		while(n > 0)
    		{
    			int mod = n % 10;
    			sum += mod * mod;
    			n /= 10;
    		}
    		if(sum == 1)
    			return true;
    		if(s.find(sum) != s.end())
    			return false;
    		s.insert(sum);
    		n = sum;
    	}
    	return false;
    }
};