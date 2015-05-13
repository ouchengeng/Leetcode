class Solution {
public:
int longestConsecutive(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	unordered_map<int, int> m;
	int ans = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		unordered_map<int, int>::iterator it;
		it = m.find(nums[i]);
		if (m.end() != it)
			continue;
		m[nums[i]] = 1;
		int begin = nums[i], end = nums[i];
		it = m.find(nums[i] + 1);
		if (it != m.end())
			end = it->second + nums[i];
		it = m.find(nums[i] - 1);
		if (it != m.end())
			begin = nums[i] - it->second;
		m[end] = end - begin + 1;
		m[begin] = end - begin + 1;
		if (end - begin + 1 > ans)
			ans = end - begin + 1;

	}
	return ans;
}
};