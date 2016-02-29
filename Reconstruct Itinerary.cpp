class Solution {
public:
bool dfs(string &cur, vector<string> &ans, unordered_map<string, vector<string>> &path, unordered_map<string, vector<bool>> &vis, int expected)
{
	ans.push_back(cur);
	if(expected == ans.size())
		return true;
	vector<string> &v = path[cur];
	vector<bool> &visit = vis[cur];
	for(int i = 0; i < v.size(); i++)
	{
		if(visit[i])
			continue;
		visit[i] = true;
		if(dfs(v[i], ans, path, vis, expected))
			return true;
		visit[i] = false;
	}
	ans.pop_back();
	return false;
}
vector<string> findItinerary(vector<pair<string, string>> tickets)
{
	unordered_map<string, vector<string>> path;
	vector<string> ans;
	ans.reserve(tickets.size() + 1);
	if(tickets.size() == 0)
		return ans;
	for(int i = 0; i < tickets.size(); i++)
	{
	    unordered_map<string, vector<string>>::iterator it;
	    it = path.find(tickets[i].first);
	    if(it == path.end())
	    {
	        vector<string> tmp;
	        tmp.reserve(300);
	        tmp.push_back(tickets[i].second);
	        path.insert(make_pair(tickets[i].first,tmp));
	    }
	    else
	        it->second.push_back(tickets[i].second);
		//path[tickets[i].first].push_back(tickets[i].second);
	}
	unordered_map<string, vector<bool>> vis;
	for(unordered_map<string, vector<string>>::iterator it = path.begin(); it != path.end(); it++)
	{
		vector<string> &v = it->second;
		sort(v.begin(),v.end());
		vector<bool> tmp(it->second.size(), false);
		vis[it->first] = tmp;
	}
	string start = "JFK";
	dfs(start, ans, path, vis, tickets.size() + 1);
	return ans;
}
};