class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int base = 1;
        while(base <= INT_MAX / 10 && base * 10 <= x)
            base *= 10;
        while(x > 0)
        {
            int upper = x / base;
            int lower = x % 10;
            if(upper != lower)
                return false;
            x = (x % base) / 10;
            base /= 100;
        }
        return true;
    }
};