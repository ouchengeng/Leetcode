class Solution {
public:
    struct node
    {
        int pos;
        long long value;
    };
    static bool cmp(node &a, node &b)
    {
        return a.value < b.value;
    };
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size = nums.size();
        vector<node> vec(size);
        for(int i = 0; i < size; i++)
        {
            node n;
            n.pos = i;
            n.value = nums[i];
            vec[i] = n;
        }
        sort(vec.begin(), vec.end(), cmp);
        for(int i = 1; i < size; i++)
            for(int j = i - 1; j >= 0; j--)
            {
                if(vec[i].value - vec[j].value <= t && abs(vec[i].pos - vec[j].pos) <= k)
                    return true;
                if(vec[i].value - vec[j].value > t)
                    break;
            }
        return false;
    }
};