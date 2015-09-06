class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX / 10;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            int l = i + 1, r = nums.size()-1;
            while(l < r)
            {
                while(l != i + 1 && l < r && nums[l] == nums[l-1])
                    l++;
                while(r != nums.size()-1 && r > l && nums[r] == nums[r+1])
                    r--;
                if(l >= r)
                    break;
                int sum = nums[i] + nums[l] + nums[r];
                if(abs(sum - target) < abs(ans - target))
                    ans = sum;
                if(sum == target)
                    break;
                if(sum < target)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }
};