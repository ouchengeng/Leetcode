class Solution {
public:
int findDuplicate(vector<int>& nums) {
    int base = nums.size()+1;
    for(int i = 0; i < nums.size(); i++)
        nums[(nums[i] % base) - 1] += base;
    int ans = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] > base * 2)
            ans = i+1;
        nums[i] %= base;
    }
    return ans;
}
};