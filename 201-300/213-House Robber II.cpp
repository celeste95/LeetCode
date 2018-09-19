class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> temp1(nums);
        vector<int> temp2(nums);
        temp1.erase(temp1.begin());
        temp2.pop_back();
        return max(robline(temp1),robline(temp2));
        
    }
    int robline(vector<int>& nums) {
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