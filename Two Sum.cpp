class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans(2, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(target - nums[i]) != m.end())
            {
                ans[0] = m[target-nums[i]] + 1;
                ans[1] = i + 1;
                return ans;
            }
            else
            {
                m[nums[i]] = i;
            }
        }
        return ans;
    }
};