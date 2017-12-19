class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(),nums.end());
	    permuteRecursive(nums, 0, result);
	    return result;
    }
    void permuteRecursive(vector<int> num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		for (int i = begin; i < num.size(); i++) {
            if (i != begin && num[i] == num[begin]) continue;
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    //swap(num[begin], num[i]);
            //不能用引用 交换begin和i两个下标对应的数组项会让数组变得无序。
		}
    }
};