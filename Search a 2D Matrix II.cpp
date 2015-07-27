class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int i = 0, j = matrix[0].size() - 1;
        while(i < matrix.size() && j >= 0)
        {
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                j--;
            else
                i++;
        }
        return false;
    }
};


class Solution {
public:
bool binarySearch(vector<int> &nums, int l, int r, int target)
{
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(nums[mid] == target)
            return true;
        else if(nums[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}

bool find(vector<vector<int>> &nums, int y1, int y2, int x1, int x2, int target)
{
    if(y1 > y2 ||  x1 > x2)
        return false;
    if(nums[y1][x1] > target || nums[y2][x2] < target)
        return false;
    int y_mid = (y1+y2) / 2;
    int x_mid = (x1+x2) / 2;
    bool res1 = false, res2 = false;
    if(nums[y_mid][x_mid] == target)
        return true;
    bool res3 = binarySearch(nums[y_mid], x1, x2, target);
    if(res3)
        return true;
    res1 = find(nums,y1, y_mid-1, x_mid+1, x2, target);
    if(res1)
        return true;
    res2 = find(nums, y_mid+1, y2, x1, x_mid-1, target);
    if(res2)
        return true;
    if(target > nums[y_mid][x_mid])
        return find(nums, y_mid+1, y2, x_mid, x2, target);
    else
        return find(nums, y1, y_mid-1,x1, x_mid, target);
}
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return false;
    int y = matrix.size();
    int x = matrix[0].size();
    return find(matrix, 0, y-1, 0, x-1, target);

}
};