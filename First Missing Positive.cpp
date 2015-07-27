class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= 0 || nums[i] > nums.size() || nums[nums[i]-1] == nums[i])
                continue;
            int pos = nums[i] - 1;
            swap(nums[pos], nums[i]);
            i--;
        }
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != i + 1)
                return i+1;
        return nums.size() + 1;
    }
};