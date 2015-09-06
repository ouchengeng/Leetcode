class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> tmp(3);
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int l = i + 1, j = nums.size()-1;
            while(l < j)
            {
                while(l != i+1 && l < j && nums[l] == nums[l-1])
                    l++;
                while(j != nums.size()-1 && l < j && nums[j] == nums[j+1])
                    j--;
                if(l >= j)
                    break;
                int sum = nums[i] + nums[l] + nums[j];
                if(sum == 0)
                {
                    tmp[0] = nums[i], tmp[1] = nums[l], tmp[2] = nums[j];
                    ans.push_back(tmp);
                    l++,j--;
                }
                else if(sum < 0)
                    l++;
                else
                    j--;
            }
        }
        return ans;
    }
};