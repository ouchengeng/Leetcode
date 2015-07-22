class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n > 1)
        {
            int digit = (n & 1);
            if(digit == 1)
                break;
            n >>=1;
        }
        if(n == 1)
            return true;
        else return false;
    }
};