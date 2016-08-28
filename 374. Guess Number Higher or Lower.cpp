int guess(int num);

class Solution {
public:
  int guessNumber(int n) {
	if(n < 1)
		return 0;
	int mid = n / 2, left = 1, right = n, ans;
	while(left <= right)
	{
		int mid = left + (right - left) / 2;
		int tmp = guess(mid);
		if(tmp == 0)
			return mid;
		else if(tmp == -1)
		{
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return ans;
}
};