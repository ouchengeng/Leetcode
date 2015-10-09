class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1 = 0, p2 = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != 0)
                nums[p1++] = nums[i];
        for(; p1 < nums.size(); p1++)
            nums[p1] = 0;
    }
};