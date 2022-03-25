

int mySqrt(int x)
{
    int root = 1,
        pow_of_two;

    if(x == 0)
        return 0;
    do
    {
        pow_of_two = 1;
        while(root < x/root)
        {
            root += pow_of_two;
            pow_of_two *= 2;
        }
        while(root > x/root)
        {
            pow_of_two /= 2;
            root -= pow_of_two;
        }
        if(root*root == x)
            return root;
    } while(pow_of_two != 1);

    return root;
}
