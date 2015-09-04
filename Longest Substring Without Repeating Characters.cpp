class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, cur = 0, len = s.length();
        int hash[128];
        for(int i = 0; i < 128; i++)
            hash[i] = -1;
        for(int i = 0; i < len; i++)
        {
            if(hash[s[i]] == -1 || hash[s[i]] + cur < i)
            {
                cur++;
                ans = max(cur, ans);
            }
            else
                cur = i - hash[s[i]];
            hash[s[i]] = i;
        }
        return ans;
    }
};