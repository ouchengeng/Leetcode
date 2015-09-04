class Solution {
public:
    int longest(string &s, int l, int r)
    {
        int ans = 0;
        while(l >= 0 && r < s.length())
        {
            if(s[l--] == s[r++])
                ans++;
            else
                break;
        }
        return ans;
    }
    string longestPalindrome(string s) {
        int ans = 1, start = 0, end = 0;
        for(int i = 0; i < s.length()-1; i++)
        {
            if((int)((s.length()-i) * 2) < (ans - 10))
                break;
            int tmp1 = longest(s, i-1, i+1);
            if(tmp1 * 2 + 1 > ans)
            {
                ans = tmp1 * 2 + 1;
                start = i - tmp1;
            }
            if(s[i] == s[i+1])
            {
                tmp1 = longest(s, i - 1, i + 2);
                if(tmp1*2 + 2 > ans)
                {
                    ans = tmp1 * 2 + 2;
                    start = i - tmp1;
                }
            }
        }
        return s.substr(start, ans);
    }
};