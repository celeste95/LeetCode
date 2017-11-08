/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i;
    int *sum;
    i=digitsSize-1;
    sum = (int*) malloc ( sizeof(int) * (digitsSize+1) );
    while(digits[i]==9)
    {
        sum[i]=0;
        i--;
    }
    if(i==-1)
    {
        sum[0]=1;
        sum[digitsSize]=0;
        *returnSize= digitsSize+1;
        return sum;
    }
    sum[i]=digits[i]+1;
    i--;
    while(i>=0) {sum[i]=digits[i];i--;}
    *returnSize= digitsSize;
    return sum;
}

