class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size();
        //从后往前查找 找到第一个小于nums[i]的nums[i-1]
        //1 3 5 4 3 2 1 a[1]<a[2] 
        while(--i) if(nums[i]>nums[i-1]) break;
        //如果原数组就是降序排列，将其升序排列
        if(i==0) 
        {
            sort(nums.begin(),nums.end());
            return;
        }
        //从后往前查找第一个大于nums[i-1]的数
        int j=nums.size();
        while(--j) if(nums[j]>nums[i-1]) break;
        //交换nums[j],nums[i-1]
        swap(nums[j],nums[i-1]);
        //将nums[i-1]后面的数升序排列
        sort(nums.begin()+i,nums.end());
        return;
    }
};