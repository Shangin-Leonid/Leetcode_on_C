/*
    ACCEPTED
    120 ms
    6.9 MB
*/

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;
    int *indices = (int*) malloc(*returnSize * sizeof(int));
    for(int i = 0; i < numsSize; i++)
        for(int j = i+1; j < numsSize; j++)
            if(nums[i] + nums[j] == target)
            {
                indices[0] = i;
                indices[1] = j;
            }
    return indices;
}
