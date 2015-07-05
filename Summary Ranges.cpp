class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0)
            return ans;
        int p = nums[0], q = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int cur = nums[i];
            if(q - cur == -1)
                q = cur;
            else
            {
                ostringstream s;
                if(p == q)
                    s << q;
                else
                    s << p << "->" << q;
                ans.push_back(s.str());
                p = q = cur;
            }
        }
        ostringstream s;
        if(p == q)
            s << q;
        else
            s << p << "->" << q;
        ans.push_back(s.str());
        return ans;
    }
};