class Solution {
public:
   int mySqrt(int x)
    {
	if(x == 0)
		return 0;
	int l = 1,  r = x, ans;
	while(l <= r)
	{
		int mid = l + (r - l) / 2;
		if((long long)mid * mid <= (long long)x)
		{
			ans = mid;
			l = mid+1;
			if((long long)mid * mid == (long long)x)
				break;
		}
		else
			r = mid-1;
	}
	return ans;
}
};