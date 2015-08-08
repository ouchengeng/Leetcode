class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> remaining(128, 0);
        int required = t.size();
        int ans = INT_MAX, left = 0, i = 0, start = 0;
        for(int i = 0; i < required; i++)
            remaining[t[i]]++;
        while(i <= s.size() && start < s.size())
        {
            if(required)
            {
                remaining[s[i]]--;
                if(remaining[s[i]] >= 0)
                    required--;
                i++;
            }
            else
            {
                if(i - start < ans)
                    {
                        ans = i - start;
                        left = start;
                    }
                remaining[s[start]]++;
                if(remaining[s[start]] > 0)
                    required++;
                start++;
            }
        }
        if(required == 0 && (i - start < ans))
        {
            ans = i - start;
            left = start;
        }
        
        return ans == INT_MAX ? "" : s.substr(left, ans);
    }
};