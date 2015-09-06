class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() == 0)
            return ans;
        vector<int> tmp(4);
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size - 3; i++)
        {
            while(i > 0 && i < size-3 && nums[i] == nums[i-1])
                ++i;
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
                break;
            if(nums[i] + nums[size-1] + nums[size-2] + nums[size-3] < target)
                continue;
            for(int j = i + 1; j <size - 2; j++)
            {
                while(j > i + 1 && j < size-2 && nums[j] == nums[j-1])
                    ++j;
                int l = j + 1, r = size-1;
                if(nums[i]+nums[j]+nums[l]+nums[l+1] > target)
                    continue;
                if(nums[i]+nums[j]+nums[r]+nums[r-1] < target)
                    continue;
                while(l < r)
                {
                    while(l != j + 1 && l < r && nums[l] == nums[l - 1])
                        ++l;
                    while(r != size-1 && l < r && nums[r] == nums[r+1])
                        --r;
                    if(l >= r)
                        break;
                    int sum = nums[i] + nums[j] + nums[r] + nums[l];
                    if(sum == target)
                    {
                        tmp[0] = nums[i], tmp[1] = nums[j], tmp[2] = nums[l], tmp[3] = nums[r];
                        ans.push_back(tmp);
                        ++l, --r;
                    }
                    else if(sum < target)
                        ++l;
                    else
                        --r;
                }
            }
        }
        return ans;
    }
};