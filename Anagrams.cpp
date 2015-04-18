class Solution {
public:
    vector<string> anagrams(vector<string> &strs) 
    {
    	vector<string> ans;
    	if(strs.size() == 0)
    		return ans;
    	unordered_map<string, pair<int, bool> > m;
    	unordered_map<string, pair<int, bool> >::iterator it;
    	for(int i = 0; i < strs.size(); i++)
    	{
    		string str = strs[i];
    		sort(str.begin(), str.end());
    		it = m.find(str);
    		if(it == m.end())
    			m[str] = make_pair(i, false);
    		else if(it->second.second == true)
    			ans.push_back(strs[i]);
    		else
    		{
    		    ans.push_back(strs[i]);
    		    ans.push_back(strs[it->second.first]);
    		    it->second.second = true;
    		}
    	}  
    	return ans;
    }
};