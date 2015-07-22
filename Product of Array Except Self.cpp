class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(nums.size());
        for(int i = size - 1; i >= 0; i--)
        {
            if(i == size - 1)
                ans[i] =  nums[i];
            else
                ans[i] = ans[i + 1] * nums[i];
        }
        int pre = 1;
        for(int i = 0; i < size; i++)
        {
            if(i == size - 1)
                ans[i] = pre;
            else
                ans[i] = pre * ans[i + 1];
            pre *= nums[i];
        }
        return ans;
    }
};