

int findShortestSubArray(int* nums, int numsSize)
{
    char *values = (char *)malloc( 50000 * sizeof(char));
    for(int i = 0; i < 50000; i++)
        values[i] = 0;
    int min_len = numsSize, count = 0, last_pos = 0, degree = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(values[nums[i]] == 1)
            continue;
        values[nums[i]] = 1;
        for(int j = i; j < numsSize; j++)
            if(nums[i] == nums[j])
            {
                count++;
                last_pos = j;
            }

        if(count > degree)
        {
            degree = count;
            min_len = last_pos - i + 1;
        }
        if(count == degree)
            if(min_len > last_pos - i + 1)
                min_len = last_pos - i + 1;
        count = 0;
    }
    free(values);
    return min_len;
}
