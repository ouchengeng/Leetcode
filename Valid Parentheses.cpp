class Solution {
public:
    bool isValid(string s) {
        stack<char> dp;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                dp.push(s[i]);
            else if(s[i] == ')')
            {
                if(dp.empty() || dp.top() != '(')
                    return false;
                dp.pop();
            }
            else if(s[i] == ']')
            {
                if(dp.empty() || dp.top() != '[')
                    return false;
                dp.pop();
            }
            else if(s[i] == '}')
            {
                if(dp.empty() || dp.top() != '{')
                    return false;
                dp.pop();
            }
            else
                return false;
        }
        return dp.empty();
    }
};