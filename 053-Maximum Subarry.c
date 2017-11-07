int maxSubArray(int* nums, int numsSize) {
    int sum = 0, max = INT_MIN;
    int i,j;
    for(i=0;i<numsSize;i++)
    {
        sum=0;
        for(j=i;j<numsSize;j++)
        {
            sum+=nums[j];
            if(sum>max) max=sum;
        }
    }
    return max;
}