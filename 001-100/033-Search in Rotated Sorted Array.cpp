class Solution {
private:
    int binsearch(vector<int>& nums,int left,int right,int target)
    {
        int mid;
        while(left<=right)
        {
            mid =(left+right)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) left=mid+1;
            else right=mid-1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        int left=0;
        int right=nums.size()-1;
        int ret;
        if(nums[left]<=nums[right]) return binsearch(nums,left,right,target);
        while(nums[left]>nums[right])
        {
            if(nums[(left+right)/2]>nums[left]) left=(left+right)/2;
            else right=(left+right)/2;
        }
        int max = nums[right];
        int min = nums[right+1];
        if (target>max || target<min) return -1;
        else
        {
            if(target >= nums[0]) ret=binsearch(nums,0,right,target);
            else 
            {
                if(target <= nums[nums.size()-1]) ret=binsearch(nums,right+1,nums.size()-1,target);
                else return -1;
            }
        }
        return ret;
    }
};