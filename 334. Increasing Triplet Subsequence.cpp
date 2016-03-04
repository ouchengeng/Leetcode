class Solution {
public:
    bool increasingTriplet(vector<int>& nums)
    {
    	int first_min = INT_MAX, second_min = INT_MAX;
    	for(int i = 0; i < nums.size(); i++)
    	{
    		if(nums[i] > second_min)
    			return true;
    		else if(nums[i] > first_min && nums[i] < second_min)
    			second_min = nums[i];
    		else if(nums[i] < first_min)
    			first_min = nums[i];
    	}
    	return false;
    }
};