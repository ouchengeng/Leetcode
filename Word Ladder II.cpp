class Solution {
public:
	vector<vector<string>> ans;
	int len;
	unordered_map<string, vector<string> > path;
    void bfs(vector<vector<string>> &cur, string &end, unordered_set<string> &dict)
    {
        vector<vector<string>> cur_1;
        bool found = false;
        for(int i = 0; i < cur.size(); i++)
            for(int j = 0; j < len; j++)
            {
                string s = cur[i].back();
                for(int k = 0; k < 26; k++)
                {
                    if('a' + k == cur[i].back()[j])
                        continue;
                    s[j] = 'a' + k;
                    if(s == end)
                    {
                        ans.push_back(cur[i]);
                        ans.back().push_back(end);
                        found = true;
                    }
                    else if(dict.find(s) != dict.end())
                    {
                        dict.erase(s);
                        cur_1.push_back(cur[i]);
                        cur_1.back().push_back(s);
                    }
                }
            }
        if(!found)
            bfs(cur_1, end, dict);
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
    {
        vector<string> tmp(1, start);
        vector<vector<string>> cur;
        cur.push_back(tmp);
        if(start == end)
        	return cur;
        len = start.length();
        bfs(cur, end, dict);
        return ans;
    }
};