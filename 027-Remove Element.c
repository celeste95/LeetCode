int removeElement(int* nums, int numsSize, int val) {
    int i,j=numsSize-1,sum=0;
    if(numsSize==0) return 0;
    if(numsSize==1)
    {
        if(nums[0]==val) return 0;
        else return 1;
    }
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]!=val) sum++;
    }
    for(i=0;i<sum;i++)
    {
        if(nums[i]==val)
        {
            while(nums[j]==val) j--;
            nums[i]=nums[j];
            j--;
        }
    }
    return sum;
}