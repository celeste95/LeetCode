int removeDuplicates(int* nums, int numsSize) {
    int i,sum=1,temp;
    if(numsSize==1||numsSize==0) return numsSize;
    for(i=1;i<numsSize;i++)
    {
        if(nums[i]!=nums[i-1])
        {
            nums[sum]=nums[i];
            sum++;
        }
    }
    return sum;
}