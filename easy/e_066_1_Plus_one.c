/*
    ACCEPTED
    0 ms    100%
    5.7 MB  97 %
*/

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int *inc_digits;
    int inc_length = 0;

    while((inc_length < digitsSize) && (digits[inc_length] == 9))
        inc_length++;

    if(inc_length == digitsSize)
    {
        inc_length++;
        inc_digits = (int *) malloc(inc_length * sizeof(int));
        inc_digits[0] = 1;
        for(int i = 1; i < inc_length; ++i)
            inc_digits[i] = 0;
    }
    else
    {
        inc_length = digitsSize;
        inc_digits = (int *) malloc(inc_length * sizeof(int));
        int tmp_index = inc_length - 1;
        while(digits[tmp_index] == 9)
        {
            inc_digits[tmp_index] = 0;
            tmp_index--;
        }
        inc_digits[tmp_index] = digits[tmp_index] + 1;
        tmp_index--;
        while(tmp_index >= 0)
        {
            inc_digits[tmp_index] = digits[tmp_index];
            tmp_index--;
        }
    }

    *returnSize = inc_length;
    return inc_digits;
}
