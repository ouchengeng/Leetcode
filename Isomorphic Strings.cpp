class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
    	char st[256] = {0};
    	char ts[256] = {0};
    	for(int i = 0; i < t.length(); i++)
    	{
    		if(st[s[i]] && st[s[i]] != t[i])
    			return false;
    		if(ts[t[i]] && ts[t[i]] != s[i])
    			return false;
    		st[s[i]] = t[i];
    		ts[t[i]] = s[i];
    	}
    	return true;
    }
};