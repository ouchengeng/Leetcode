class Solution {
public:
    struct node
    {
        int l, r;
        node():l(INT_MAX),r(INT_MIN){
        }
    };
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        int l = INT_MAX, r = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            r = max(r, nums[i]);
            l = min(l, nums[i]);
        }
        int gap = (r - l) / (nums.size()-1);
        gap = max(gap, 1);
        int num = (r - l) / gap + 1;
        node *bus = new node[num];
        for(int i = 0; i < nums.size(); i++)
        {
            int pos = (nums[i] - l) / gap;
            bus[pos].l = min(bus[pos].l, nums[i]);
            bus[pos].r = max(bus[pos].r, nums[i]);
        }
        int previous = l, result = INT_MIN;
        for(int i = 0; i < num; i++)
        {
            if(bus[i].l != INT_MAX)
                result = max(result, bus[i].l - previous);
            if(bus[i].r != INT_MIN)
                previous = bus[i].r;
        }
        return result;
    }
};