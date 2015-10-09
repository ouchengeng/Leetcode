class Solution {
public:
    int ans = 9;
    bool helper(int value, int pos)
    {
    	if(pos == 5 || value <= 0 || pos >= ans)
    		return false;
    	int split = sqrt((double)value);
    	if(split * split == value)
    	{
    		ans = min(ans,pos);
    		return true;
    	}
    	for(int i = split; i >= 1; i--)
    		    helper(value-i*i, pos+1);
    	return false;
    
    }
    int numSquares(int n)
    {
    	helper(n, 1);
    	return ans;
    }
};