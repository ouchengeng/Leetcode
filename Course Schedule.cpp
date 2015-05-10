class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
    	int n = prerequisites.size();
    	if(n * numCourses == 0)
    		return true;
    	stack<int> zero;
    	vector<int> inDegree(numCourses, 0);
    	vector<vector<int> > graph(numCourses, vector<int>(0, 0));
    	for(int i = 0; i < n; i++)
    	{
    		int pre = prerequisites[i][0];
    		int after = prerequisites[i][1];
    		graph[pre].push_back(after);
    		inDegree[after]++;
    	}
    	for(int i = 0; i < numCourses; i++)
    		if(inDegree[i] == 0)
    			zero.push(i);
    	while(!zero.empty())
    	{
    		int take = zero.top();
    		zero.pop();
    		for(int i = 0; i < graph[take].size(); i++)
    		{
    			int after = graph[take][i];
    			inDegree[after]--;
    			if(inDegree[after] == 0)
    				zero.push(after);
    		}
    	}
    	for(int i = 0; i < numCourses; i++)
    		if(inDegree[i] != 0)
    			return false;
    	return true;
    }
};