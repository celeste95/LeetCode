class Solution {
private:
    vector<vector<int>> ret;
    void find(vector<int>& nums,int start,int end,int target)
    {
        int l = start, r = end;  
        while (l < r) {  
            if (nums[l] + nums[r] + target == 0) {  
                vector<int> set;  
                set.push_back(nums[l]);
                set.push_back(nums[r]);
                set.push_back(target);
                ret.push_back(set); //放入结果集中  
                while (l < r && nums[l] == nums[l+1]) l++;  
                while (l < r && nums[r] == nums[r-1]) r--;  
                l++;  
                r--;  
            } else if (nums[l] + nums[r] + target < 0) {  
                l++;  
            } else {  
                r--;  
            }  
        }  
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return ret;
        sort(nums.begin(),nums.end());
        for(int i = 0; nums[i]<=0 && i<nums.size()-2; i++)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            find(nums,i+1,nums.size()-1,nums[i]);
        }
        return ret;
    }
};