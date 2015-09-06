class Solution {
public:
int hIndex(vector<int>& citations) {
    vector<int> &v =  citations;
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int ans = 0, flag = 0;
	int low = 0, high = citations.size()-1;
	while(low <= high)
	{
		int mid = (low+high)/2;
		if(citations[mid] < mid + 1)
			high = mid - 1;
		else
		{
			low = mid + 1;
			ans = mid, flag = 1;
		}
	}
	return ans + flag;
}
};

//
class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> &v = citations;
        if(v.size() == 0)
            return 0;
        int n = v.size(), sum = 0;
        vector<int> hash(n+1, 0);
        for(int i = 0; i < n; i++)
        {
            if(v[i] >= n)
                hash[n]++;
            else
                hash[v[i]]++;
        }        
        for(int i = n; i >= 0; i--)
        {
            sum += hash[i];
            if(i <= sum)
                return i;
        }
        return 0;
    }
};