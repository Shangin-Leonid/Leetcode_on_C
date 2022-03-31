
int removeElement(int* nums, int numsSize, int val)
{
    if((numsSize == 0) || (nums == NULL))
        return 0;
    int left = 0, right = numsSize - 1;
    while(left < right)
    {
        while((left < right) && (nums[left] != val)) left++;
        while((left < right) && (nums[right] == val)) right--;
        if(left < right)
            nums[left] = nums[right--];
    }
    if((right == left) && (nums[right] == val))
        right--;
    return right + 1;
}
