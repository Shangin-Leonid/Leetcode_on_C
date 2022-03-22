

bool isPowerOfTwo(int n)
{
    if(n <= 0)
        return false;

    int mask = 1;

    for(int i = 2; i < sizeof(int)*8; ++i)
    {
        if(mask == n)
            return true;
        mask <<= 1;
    }
    if(mask == n)
        return true;

    return false;
}
