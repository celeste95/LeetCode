class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		//my solution
        int right=0,left=0;
        while(right<nums.size())
        {
            if(nums[right]==0) right++;
            else
            {
                swap(nums[left],nums[right]);
                left++;
                right++;
            }
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++) {
			//example
            if (nums[i]) {
                if (i != j) {
                    swap(nums[i], nums[j++]);    
                } else {
                    j++;   
                }
            }
        }
    }
};