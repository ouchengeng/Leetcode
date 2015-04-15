class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
    	if(nums.size() == 0)
    		return 0;
    	int ans = nums[0], cur = nums[0];
    	for(int i = 1; i < nums.size(); i++)
    	{
    		cur = max(cur + nums[i], nums[i]);
    		ans = max(cur, ans);
    	}
    	return ans;
    }
};