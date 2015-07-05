class Solution {
public:
vector<int> majorityElement(vector<int>& nums) {
	map<int, int> value;
	map<int, int>::iterator it;
	for(int i = 0; i < nums.size(); i++)
	{
		it = value.find(nums[i]);
		if(it == value.end()) //不存在
			value[nums[i]] = 1;
		else
			it->second++;
		if(value.size() < 3)
			continue;
		it = value.begin();
		while(it != value.end())
		{
			map<int,int>::iterator e = it;
			it++;
			e->second--;
			if(e->second == 0)
				value.erase(e);
		}
	}
	vector<int> ans;
	for(it = value.begin(); it != value.end(); it++)
	    it->second = 0;
	for(int i = 0; i < nums.size(); i++)
	    {
	        it = value.find(nums[i]);
	        if(it != value.end())
	            it->second++;
	    }
	for(it = value.begin(); it != value.end(); it++)
	    if(it->second > nums.size() / 3)
	        ans.push_back(it->first);
	return ans;
}
};