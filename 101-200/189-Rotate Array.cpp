class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		//Solution 1
        k=k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        return;
    }
	
	
	void rotate(vector<int>& nums, int k) {
		//Solution 2
        vector<int> temp=nums;
        k=k%nums.size();
        for(int i=0;i<nums.size();i++)
        {
            nums[(i+k)%nums.size()]=temp[i];
        }
        return;
    }
};