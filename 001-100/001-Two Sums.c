/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i,j,flag=0;
    int* result=NULL;
    result=(int*)malloc(2*sizeof(int));
    for(i=0; i<numsSize; i++)
    {
        for(j=i+1; j<numsSize; j++)
        {
            if(nums[i]+nums[j]==target)
            {
                flag=1;
                break;
            }
        }
        if(flag) break;
    }
    result[0]=i;
    result[1]=j;
    return result;
}
