
//bruce force

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


//DP

int maxSubArray(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int ret = nums[0];
    int lmax = ret;
    for (int i = 1; i < numsSize; i++) {
        lmax = (lmax>0?lmax:0) + nums[i];
        ret = lmax>ret?lmax:ret;
    }
    return ret;
}
