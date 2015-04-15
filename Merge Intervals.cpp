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
    void mergeInterval(Interval &v1, Interval &v2)
    {
    	// put v2 into v1
    	v1.start = min(v1.start, v2.start);
    	v1.end = max(v1.end, v2.end);
    }
    static bool cmp(Interval &v1, Interval &v2)
    {
    	return v1.start < v2.start;
    }
    vector<Interval> merge(vector<Interval> &intervals)
    {
    	vector<Interval> ans;
    	if(intervals.size() == 0)
    		return ans;
    	sort(intervals.begin(), intervals.end(), cmp);
    	int i;
    	for(i = 0; i <intervals.size() - 1; i++)
    	{
    		bool is = isOverlapping(intervals[i], intervals[i + 1]);
    		if(!is)
    			ans.push_back(intervals[i]);
    		else
    			mergeInterval(intervals[i + 1], intervals[i]);
    	}
    	if(ans.size() == 0 || isOverlapping(intervals[i], ans[ans.size()-1]) == false)
    		ans.push_back(intervals[i]);
    	return ans;
    }
};