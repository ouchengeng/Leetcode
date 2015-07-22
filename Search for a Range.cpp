class Solution {
public:
    int last(vector<int> &nums, int target)
    {
    	int hit = -1;
    	int left = 0, right = nums.size()-1;
    	while(left <= right)
    	{
    		int mid = (left+right) / 2;
    		if(nums[mid] <= target)
    		{
    			if(nums[mid] == target)
    				hit = mid;
    			left = mid + 1;
    		}
    		else
    			right = mid - 1;
    	}
    	return hit;
    }
    int first(vector<int> &nums, int target)
    {
    	int left = 0, right = nums.size() - 1;
    	int hit = -1;
    	while(left <= right)
    	{
    		int mid = (left+right) / 2;
    		if(nums[mid] >= target)
    		{
    			if(nums[mid] == target)
    				hit = mid;
    			right = mid - 1;
    		}
    		else
    			left = mid + 1;
    	}
    	return hit;
    }
    vector<int> searchRange(vector<int>& nums, int target)
    {
    	vector<int> ans(2, -1);
    	int start = first(nums, target);
    	if(start != -1)
    	{
    		ans[0] = start;
    		ans[1] = last(nums, target);
    	}
    	return ans;
    }
};