int rangeBitwiseAnd(int m, int n)
{
    int bit = 0;
    while(m != n)
    {
        m >>= 1;
        n >>= 1;
        bit++;
    }
    return n << bit;
}