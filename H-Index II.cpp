class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> &v =  citations;
    	if(v.size() == 0)
    	    return 0;
    	int ans = 0, flag = 0;
    	int low = 0, high = citations.size()-1;
    	while(low <= high)
    	{
    		int mid = (low+high)/2;
    		if(citations[mid] < v.size() - mid)
    			low = mid + 1;
    		else
    		{
    			high = mid - 1;
    			ans = mid, flag = 1;
    		}
    	}
    	if(flag == 0)
    	    return 0;
    	return v.size() - ans;
    }
};