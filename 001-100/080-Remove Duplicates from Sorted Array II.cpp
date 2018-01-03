class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //my solution
        vector<int> copy(nums);
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        if(nums.size()==2) return 2;
        int cnt=2;
        int flag=0;
        for(int i=2; i<copy.size(); i++)
        {
            if(nums[i]!=copy[i-2])
            {
                nums[cnt]=copy[i];
                cnt++;
            }
        }
        return cnt;
    }
};


int removeDuplicates(vector<int>& nums) {
    //example
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}