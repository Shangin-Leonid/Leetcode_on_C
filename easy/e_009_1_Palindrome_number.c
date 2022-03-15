/*
    ACCEPTED
    8 ms
    5.8 MB
*/

bool isPalindrome(int x)
{
    if(x < 0) return false;
    int arr_of_num[10];
    int order_of_x;

    for(order_of_x = 0; x != 0; order_of_x++, x/=10)
        arr_of_num[order_of_x] = x%10;
    for(int i = 0; i < order_of_x/2; i++)
        if(arr_of_num[i] != arr_of_num[order_of_x - 1 - i])
            return false;

    return true;
}
