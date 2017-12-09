class Solution {
private:
    vector<vector<int>> ret;
    void find4(vector<int>& nums,int start,int end,int ans1,int target)
    {
        for(int i=start; i<end; i++)
        {
            if(i!=start && nums[i]==nums[i-1]) continue;
            find(nums,i+1,end,nums[i],ans1,target);
        } 
    }
    void find(vector<int> &nums,int start,int end,int ans2,int ans1,int target)
    {
        int l = start, r = end;  
        while (l < r) {  
            if (nums[l] + nums[r] + ans2 + ans1 == target) {  
                vector<int> set;  
                set.push_back(nums[l]);
                set.push_back(nums[r]);
                set.push_back(ans2);
                set.push_back(ans1);
                ret.push_back(set); //放入结果集中  
                while (l < r && nums[l] == nums[l+1]) l++;  
                while (l < r && nums[r] == nums[r-1]) r--;  
                l++;  
                r--;  
            } else if (nums[l] + nums[r] + ans2 + ans1 < target) {  
                l++;  
            } else {  
                r--;  
            }  
        } 
    }
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        if(nums.size()<4) return ret;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size()-3; i++)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            find4(nums,i+1,nums.size()-1,nums[i],target);
        }
        return ret;
    }
};