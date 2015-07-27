class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n == 0)
            return 0;
        int i = 0, j = n - 1, best = 0;
        while(i < j)
        {
            best = max(best, min(height[i],height[j])*(j - i));
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return best;
    }
};