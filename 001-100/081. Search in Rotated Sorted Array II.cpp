class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0) return false;
        if(nums.size()==1) return nums[0]==target;
        if(nums[0]<nums[nums.size()-1]) return binary_search(nums.begin(),nums.end(),target);
        int i;
        for(i=0;i<nums.size()-1;i++) if(nums[i]>nums[i+1]) break;
        return binary_search(nums.begin(),nums.begin()+i+1,target)||binary_search(nums.begin()+i+1,nums.end(),target);
    }
};