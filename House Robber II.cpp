class Solution {
public:
    int solve(vector<int>&nums, int start, int end)
    {
        int cur2 = 0, cur1 = nums[start];
        int vis2 = false, vis1 = true;
        for(int i = (start + 1) % nums.size(); i != end; i = (i+1)%nums.size())
        {
            int cur = 0;
            bool vis = false;
            if(!vis1)
            {
                cur = nums[i] + cur1;
                vis = true;
            }
            else
            {
                int join = cur2 + nums[i];
                if(join <= cur1)
                {
                    cur = cur1;
                    vis = false;
                }
                else
                {
                    cur = join;
                    vis = true;
                }
            }
            vis2 = vis1, cur2 = cur1;
            vis1 = vis, cur1 = cur;
        }
        return cur1;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        return max(solve(nums, 0, nums.size()-1), solve(nums, 1, 0) );
    }
};