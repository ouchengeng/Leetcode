class Solution {
public:
int jump(vector<int>& nums)
{
    int curMax = nums[0], maxLen = nums[0], step = 1;
    int n = nums.size();
    for(int i = 1; i < max(n, maxLen); i++)
    {
        if(nums[i] + i > maxLen)
            maxLen = nums[i] + i;
        if(i >= n - 1)
            return step;
        if(i == curMax)
        {
            curMax = maxLen;
            step++;
        }
    }
    return 0;
}
};