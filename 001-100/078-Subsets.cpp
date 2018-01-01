class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size()==0)
        {
            vector <vector<int>> ret;
            vector<int> ret1;
            ret.push_back(ret1);
            return ret;
        }
        vector<int> tempnums(nums);
        int last = tempnums[tempnums.size()-1];
        tempnums.pop_back();
        vector<vector<int>> lastsubsets;
        lastsubsets=subsets(tempnums);
        int length=lastsubsets.size();
        for(int i=0;i<length;i++)
        {
            vector<int> temp(lastsubsets[i]);
            temp.push_back(last);
            lastsubsets.push_back(temp);
        }
        return lastsubsets;
    }
};