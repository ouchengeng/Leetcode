/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool isOverlapping(Interval &v1, Interval &v2)
    {
    	if((v2.start <= v1.end && v2.start >= v1.start )
    		||
    		(v1.start <= v2.end && v1.start >= v2.start))
    		return true;
    	return false;
    }
    void merge(Interval &v1, Interval &v2)
    {
    	// put v2 into v1
    	v1.start = min(v1.start, v2.start);
    	v1.end = max(v1.end, v2.end);
    }
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
    {
    	vector<Interval> ans;
    	if(intervals.size() == 0)
    	{
    	    ans.push_back(newInterval);
    	    return ans;
    	}
    	bool newIn = false;
    	for(int i = 0; i < intervals.size(); i++)
    	{
    		bool is = isOverlapping(intervals[i], newInterval);
    		if(is)
    			merge(newInterval, intervals[i]);
    		else
    		{
    			if(intervals[i].start < newInterval.start)
    				ans.push_back(intervals[i]);
    			else
    			{
    				ans.push_back(newInterval);
    				newIn = true;
    				for(int j = i; j < intervals.size(); j++)
    					ans.push_back(intervals[j]);
    				break;
    			}
    		}
    	}
    	if(!newIn)
    	    ans.push_back(newInterval);
    	return ans;
    }
};