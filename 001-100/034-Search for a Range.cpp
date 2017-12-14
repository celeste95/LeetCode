class Solution {
private:
    int binsearch(vector<int>& nums,int left,int right,int target)
    {
        if(right<left) return -1;
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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        if(nums.empty()) return {-1,-1};
        int find = binsearch(nums,0,nums.size()-1,target);
        if(find==-1)
        {
            ret.push_back(-1);
            ret.push_back(-1);
        }
        else
        {
            int left=binsearch(nums,0,find,target);
            int right=binsearch(nums,find,nums.size()-1,target);
            while(binsearch(nums,0,left,target)!=-1) left--;
            while(binsearch(nums,right,nums.size()-1,target)!=-1) right++;
            ret.push_back(left+1);
            ret.push_back(right-1);
        }
        return ret;
    }
};