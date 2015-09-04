class Solution {
public:
    int reverse(int x) {
        int sign = 1, ans = 0;
        if(x < 0)
        {
            sign = -1;
            x = -x;
        }
        while(x > 0)
        {
            if(ans > INT_MAX / 10)
                return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return sign * ans;
    }
};