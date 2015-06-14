class Solution {
public:
    void swap(vector<int> &nums, int l, int r)
    {
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
    }
    int solve(vector<int> &nums, int k, int l, int r)
    {
        int pos = l - 1;
        int target = nums[r];
        for(int i = l; i <= r; i++)
            if(nums[i] < target)
                swap(nums, ++pos, i);
        swap(nums, r, ++pos);
        if(r - pos + 1 == k)
            return nums[pos];
        else if(r - pos + 1 > k)
            return solve(nums, k, pos + 1, r);
        else return solve(nums, k - (r - pos + 1), l, pos - 1);
    }
    int findKthLargest(vector<int>& nums, int k)
    {
        return solve(nums, k, 0, nums.size()-1);
    }
};