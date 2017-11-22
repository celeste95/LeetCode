class Solution {
public:
    int rob(vector<int>& nums) {
		//TLE
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> temp1=nums;
        vector<int> temp2=nums;
        temp1.pop_back();
        temp1.pop_back();
        temp2.pop_back();
        temp2.pop_back();
        temp2.pop_back();
        return max(nums[nums.size()-1]+rob(temp1),
                   nums[nums.size()-2]+rob(temp2));
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
		// DP Accepted
        if(nums.size()==0) return 0;
        vector<int> money(nums.size());
        money[0]=nums[0];
        if(nums.size()>=2) money[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++) 
            money[i]=max(nums[i]+money[i-2],money[i-1]);
        return money[nums.size()-1];
    }
};