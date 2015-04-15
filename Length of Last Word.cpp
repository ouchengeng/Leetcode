class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, cur = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            {
                if(ans != 0)
                    cur = ans;
                ans = 0;
            }
            else
                ans++;
        }
        if(s.length() == 0)
            return 0;
        else if(s[s.length() - 1] == ' ')
            return cur;
        return ans;
    }
};