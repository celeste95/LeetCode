int searchInsert(int* nums, int numsSize, int target) {
    int idx=0;
    while(nums[idx]<target&&idx<numsSize) idx++;
    return idx;
}