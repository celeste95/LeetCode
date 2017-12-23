class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> reachable(nums.size(),false);
        reachable[0]=true;
        int max=0;
        for(int i=0;i<nums.size();i++)
        {
            if(!reachable[i]) return false;
            if((i+nums[i])>max) 
            {
                //max=i+nums[i];
                for(int j=max+1;j<=i+nums[i] && j<nums.size();j++)
                {
                    reachable[j]=true;
                }
                max=i+nums[i];
            }
        }
        return true;
    }
};
