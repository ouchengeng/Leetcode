class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0 || strs[0].length() == 0)
            return "";
        int len = 0;
        while(len < strs[0].size())
        {
            int i;
            for(i = 1; i < strs.size(); i++)
                if(len >= strs[i].size() ||  strs[i][len] != strs[0][len])
                    break;
            if(i == strs.size())
                len++;
            else
                break;
        }
        return strs[0].substr(0, len);
    }
};