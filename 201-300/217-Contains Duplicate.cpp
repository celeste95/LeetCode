class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		//TLE
        vector<int> array;
        for(int i=0;i<nums.size();i++)
        {
            if(array.end()!=find(array.begin(),array.end(),nums[i])) return true;
            else array.push_back(nums[i]);
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		//Accepted
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[i]) return true;
        }
        return false;
    }
};