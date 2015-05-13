class Solution {
public:
int minSubArrayLen(int s, vector<int>& nums)
{
    int pos = 0;
    int sum = 0;
    int ans = INT_MAX;
    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        while(sum >= s && pos <= i)
        {
            if(i - pos + 1 < ans)
                ans = i - pos + 1;
            sum -= nums[pos++];
        }
    }
    if(ans == INT_MAX)
        return 0;
    return ans;
}
};