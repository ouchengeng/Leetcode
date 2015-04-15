class Solution {
public:
    double myPow(double x, int n)
    {
    	if(n == 0)
    		return 1;
    	else if(n == 1)
    		return x;
    	double ans = pow(x, n / 2);
    	if(n % 2 == 0)
    		return ans * ans;
    	else
    		return x * ans * ans;
    }
    double pow(double x, int n) 
    {
        double ans;
        if(n < 0)
            return 1.0 / myPow(x, -n);
        else
            return myPow(x, n);
    }
};