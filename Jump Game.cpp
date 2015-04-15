class Solution {
public:
    bool canJump(vector<int>& nums)
    {
    	int n = 0;
    	for(int i = 0; i < nums.size(); i++)
    	{
    		if(n < i)
    			return false;
    		int t = nums[i] + i;
    		if(t > n)
    			n = t;
    		if(n >= nums.size() - 1)
    		    return true;
    	}
    	return n >= nums.size() - 1;
    }
};